#include "chopper_recomp_hooks.h"
#include "funcs.h"

#include <math.h>
#include <stdbool.h>
#include <string.h>

// Addresses and actor fields used by the USA game's lock-on scan (0x80022C88).
static const gpr vehicle_list = S32(0x801297F0);
static const gpr aircraft_list = S32(0x801299F0);
static const gpr lock_range = S32(0x8012974C);
static const float full_turn = 6.28318530718f;

typedef struct {
    float x, y, z;
} Vector;

typedef struct {
    gpr actor;
    Vector position;
    float pitch;
    float yaw;
    float score;
    float screen_x;
    float screen_y;
} Target;

typedef enum {
    TARGET_GROUND = 1,
    TARGET_AIR = 2,
    TARGET_ANY = TARGET_GROUND | TARGET_AIR,
    TARGET_BOMB = 4,
} TargetFilter;

static bool valid_address(gpr address, uint32_t size) {
    const gpr ram_start = S32(0x80000000);
    const gpr ram_end = S32(0x80400000);
    return address >= ram_start && address <= ram_end - size &&
           (address & 3) == 0;
}

static float read_float(uint8_t* rdram, gpr address) {
    const int32_t bits = MEM_W(0, address);
    float value;
    memcpy(&value, &bits, sizeof(value));
    return value;
}

static void write_float(uint8_t* rdram, gpr address, float value) {
    int32_t bits;
    memcpy(&bits, &value, sizeof(bits));
    MEM_W(0, address) = bits;
}

static Vector read_vector(uint8_t* rdram, gpr address) {
    return (Vector){read_float(rdram, address), read_float(rdram, address + 4),
                    read_float(rdram, address + 8)};
}

static void write_vector(uint8_t* rdram, gpr address, Vector value) {
    write_float(rdram, address, value.x);
    write_float(rdram, address + 4, value.y);
    write_float(rdram, address + 8, value.z);
}

static bool project(uint8_t* rdram, recomp_context* ctx, gpr scratch, Vector position,
                    float* screen_x, float* screen_y) {
    // Reuse the stock projection and its behind-camera test. The guest routine
    // uses the stack below this caller, with the point and result in our frame.
    recomp_context projection = *ctx;
    projection.r29 = scratch;
    projection.r4 = scratch + 0x20;
    projection.r5 = scratch + 0x28;
    write_vector(rdram, projection.r5, position);
    func_8000C94C(rdram, &projection);
    if (!projection.r2) return false;
    *screen_x = read_float(rdram, scratch + 0x20);
    *screen_y = read_float(rdram, scratch + 0x24);
    return fabsf(*screen_x) <= 160.0f && fabsf(*screen_y) <= 120.0f;
}

// Cluster bombs use a speed of 3 units per frame and pitch down by .002
// turns per frame until they reach -.25 turns (0x80040950 and 0x80041034).
static float bomb_height_at(float pitch, float distance) {
    float forward = 0.0f;
    float height = 0.0f;
    for (int frame = 0; frame < 40; ++frame) {
        if (pitch > -0.25f) pitch -= 0.002f;
        const float step = 3.0f * cosf(pitch * full_turn);
        const float rise = 3.0f * sinf(pitch * full_turn);
        if (step <= 0.0f) break;
        if (forward + step >= distance) {
            return height + rise * ((distance - forward) / step);
        }
        forward += step;
        height += rise;
    }
    return NAN;
}

static bool bomb_pitch(Vector delta, float distance, float* pitch) {
    if (delta.y >= 0.0f || distance >= 120.0f) return false;
    // Look for a downward launch that reaches the target height within the
    // original bomb's lifetime. An unreachable target keeps the stock drop.
    float previous = 0.0f;
    for (int step = 0; step <= 24; ++step) {
        const float candidate = -(float)step * 0.01f;
        const float height = bomb_height_at(candidate, distance);
        if (!isfinite(height)) break;
        if (height <= delta.y) {
            float low = candidate;
            float high = previous;
            for (int i = 0; i < 8; ++i) {
                const float middle = (low + high) * 0.5f;
                if (bomb_height_at(middle, distance) > delta.y) high = middle;
                else low = middle;
            }
            *pitch = (low + high) * 0.5f;
            return true;
        }
        previous = candidate;
    }
    return false;
}

static bool clear_terrain(uint8_t* rdram, recomp_context* ctx, gpr scratch,
                          Vector origin, Vector delta, float horizontal) {
    // The projection test does not detect ridges in front of the target.
    // Query the same terrain height used by the flight collision code.
    const int samples = 2 + (int)(horizontal / 100.0f);
    for (int sample = 1; sample < samples; ++sample) {
        const float t = (float)sample / (float)samples;
        const Vector point = {origin.x + t * delta.x, origin.y + t * delta.y,
                              origin.z + t * delta.z};
        recomp_context terrain = *ctx;
        terrain.r29 = scratch;
        terrain.r4 = scratch + 0x10;
        terrain.r5 = scratch + 0x20;
        write_vector(rdram, terrain.r5, point);
        func_8000D3A4(rdram, &terrain);
        if (terrain.r2 && read_float(rdram, scratch + 0x14) > point.y + 2.0f) return false;
    }
    return true;
}

static void consider_target(uint8_t* rdram, recomp_context* ctx, gpr scratch,
                            Target* best, gpr actor, Vector position, Vector origin,
                            float range, TargetFilter filter) {
    const Vector delta = {position.x - origin.x, position.y - origin.y, position.z - origin.z};
    const float horizontal = hypotf(delta.x, delta.z);
    const float distance = hypotf(horizontal, delta.y);
    if (!(distance > 1.0f && distance < range)) return;
    float screen_x, screen_y;
    if (!project(rdram, ctx, scratch, position, &screen_x, &screen_y)) return;
    const float x = screen_x / 160.0f;
    const float y = screen_y / 120.0f;
    const float score = 3.0f - x * x - y * y - distance / range;
    if (score <= best->score) return;
    float pitch = atan2f(delta.y, horizontal) / full_turn;
    if (filter == TARGET_BOMB && !bomb_pitch(delta, horizontal, &pitch)) return;
    if (!clear_terrain(rdram, ctx, scratch, origin, delta, horizontal)) return;
    *best = (Target){actor, position, pitch, atan2f(-delta.x, -delta.z) / full_turn,
                     score, screen_x, screen_y};
}

static Target choose_target(uint8_t* rdram, recomp_context* ctx, gpr player, Vector origin,
                            TargetFilter filter) {
    Target best = {0};
    if (!valid_address(player, 0x144)) return best;
    const float range = read_float(rdram, lock_range);
    if (!(range > 0.0f && range <= 1000.0f)) return best;
    const gpr scratch = ADD32(ctx->r29, -0x40);
    if (!valid_address(scratch - 0x500, 0x540)) return best;

    const gpr lists[] = {vehicle_list, aircraft_list};
    for (unsigned list = 0; list < 2; ++list) {
        const gpr head = (gpr)MEM_W(0, lists[list]);
        if (!valid_address(head, 4)) continue;
        gpr actor = (gpr)MEM_W(0, head);
        // The last node is a sentinel. The main actor list contains both
        // ground models and aircraft. The second list is aircraft only.
        for (unsigned visited = 0; visited < 512 && valid_address(actor, 0x9A); ++visited) {
            const gpr next = (gpr)MEM_W(0, actor);
            if (!next || next == actor) break;
            const gpr current = actor;
            actor = next;
            if (current == player || MEM_H(0x2E, current) <= 0) continue;
            const uint16_t flags = MEM_HU(list == 0 ? 0x98 : 0x92, current);
            const bool ground = list == 0 && (flags & TARGET_GROUND);
            if (ground) {
                // The cannon's collision pass accepts active, damageable ground
                // models even if they lack the stock missile lock flag (0x200).
                if (filter == TARGET_AIR || (flags & 4) || MEM_H(0x96, current) <= 0 ||
                    MEM_H(0x32, current) != 0) continue;
                const int count = MEM_H(0x2C, current);
                const gpr hitboxes = (gpr)MEM_W(0x28, current);
                if (count < 1 || count > 64 || !valid_address(hitboxes, count * 0x18)) continue;
                for (int i = 0; i < count; ++i) {
                    const gpr sphere = hitboxes + i * 0x18;
                    if (MEM_H(0x14, sphere) <= 0) continue;
                    // 0x8001EFF8 updates these world-space collision centers
                    // from the model transform, including rotated offsets.
                    consider_target(rdram, ctx, scratch, &best, current,
                                    read_vector(rdram, sphere + 8), origin, range, filter);
                }
                continue;
            }
            if (!(flags & 0x200) || filter == TARGET_GROUND || filter == TARGET_BOMB ||
                (list == 0 && !(flags & TARGET_AIR))) continue;

            Vector position = read_vector(rdram, current + 0x8);
            const gpr hitbox = (gpr)MEM_W(0x28, current);
            if (valid_address(hitbox, 8) && MEM_H(0, hitbox) == 0) {
                position.x += MEM_H(2, hitbox);
                position.y += MEM_H(4, hitbox);
                position.z += MEM_H(6, hitbox);
            }
            consider_target(rdram, ctx, scratch, &best, current, position, origin, range, filter);
        }
    }
    return best;
}

static gpr aim_launch(uint8_t* rdram, recomp_context* ctx, gpr player, gpr scratch,
                      TargetFilter filter) {
    const Target target = choose_target(rdram, ctx, player, read_vector(rdram, ctx->r5), filter);
    if (target.actor) {
        write_vector(rdram, scratch, (Vector){target.pitch, target.yaw, 0.0f});
        ctx->r6 = scratch;
    }
    return target.actor;
}

void chopper_aim_cannon(uint8_t* rdram, recomp_context* ctx) {
    // The caller has finished using this matrix scratch area. Leave the
    // helicopter rotation alone and pass the assisted angles to the shot only.
    aim_launch(rdram, ctx, ADD32(ctx->r6, -0x14), ctx->r29 + 0x54, TARGET_ANY);
    func_8003F3A4(rdram, ctx);
}

void chopper_aim_secondary(uint8_t* rdram, recomp_context* ctx) {
    const uint16_t launch_type = MEM_HU(0x12, ctx->r29);
    const uint16_t subtype = launch_type & 0xF;
    const uint16_t mode = launch_type >> 4;
    TargetFilter filter = TARGET_ANY;
    if (subtype == 3) filter = TARGET_BOMB;
    if (subtype <= 2 && mode == 0) filter = TARGET_GROUND;
    if (subtype <= 2 && mode == 1) filter = TARGET_AIR;
    const gpr target = aim_launch(rdram, ctx, ADD32(ctx->r6, -0x14), ctx->r29 + 0x44, filter);
    // Only the homing subtypes read the extra target argument. Pass the same
    // actor the launch angles were computed for, including on an initial lock.
    if (target && (subtype == 1 || subtype == 2 || subtype == 5 || subtype == 6)) {
        MEM_W(0x14, ctx->r29) = (int32_t)target;
    }
    func_80040194(rdram, ctx);
}

static int selected_weapon(uint8_t* rdram, gpr player) {
    if (!valid_address(player, 0x144)) return 0;
    const int slot = MEM_H(0xDC, player);
    const gpr loadout = S32(0x80129438);
    if (slot < 0 || slot >= 5 || MEM_H(slot * 4 + 2, loadout) <= 0) return 0;
    return MEM_H(slot * 4, loadout);
}

static Target target_for_weapon(uint8_t* rdram, recomp_context* ctx, gpr player, int weapon) {
    if (!valid_address(player, 0x144)) return (Target){0};
    TargetFilter filter = TARGET_ANY;
    if (weapon == 1) filter = TARGET_GROUND;
    if (weapon == 2) filter = TARGET_AIR;
    if (weapon == 6) filter = TARGET_BOMB;
    Vector origin = read_vector(rdram, player + 8);
    if (filter == TARGET_BOMB) origin.y += 2.0f;
    return choose_target(rdram, ctx, player, origin, filter);
}

void chopper_aim_reticle(uint8_t* rdram, recomp_context* ctx, gpr player) {
    const int weapon = selected_weapon(rdram, player);
    if (weapon != 4) {
        const Target target = target_for_weapon(rdram, ctx, player, weapon);
        if (target.actor) write_vector(rdram, ctx->r5, target.position);
    }
    func_8000C94C(rdram, ctx);
}

void chopper_draw_lock(uint8_t* rdram, recomp_context* ctx) {
    const gpr player = ctx->r4;
    const bool cannon = (MEM_HU(0, S32(0x800DD1BA)) & 0x2000) != 0;
    const int weapon = cannon ? 0 : selected_weapon(rdram, player);
    if (weapon != 4) {
        const Target lock = target_for_weapon(rdram, ctx, player, weapon);
        if (lock.actor) {
            // Draw the native lock brackets even with an empty weapon loadout.
            recomp_context marker = *ctx;
            marker.r29 = ADD32(ctx->r29, -0x30);
            marker.r4 = (int32_t)lock.screen_x;
            marker.r5 = (int32_t)lock.screen_y;
            marker.r6 = 0xFF00;
            marker.r7 = 0x17;
            MEM_W(0x10, marker.r29) = 0;
            MEM_W(0x14, marker.r29) = 0;
            func_8004C580(rdram, &marker);
        }
    }
    func_800233C4(rdram, ctx);
}
