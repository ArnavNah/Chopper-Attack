# Runtime and audio repairs

- Corrected aspMain ROM text to 0x66F90, RSP address 0x1080, length 0xE1C. The old range started inside the program and omitted handlers. The corrected end excludes following data.
- Registered all 16 audio command handlers from the ROM dispatch table at 0x7BF00 as indirect branch targets.
- Compiled rsp/aspMain.cpp and removed the no-op audio implementation.
- Routed func_80059810 (osSpTaskYielded) to the host runtime implementation, avoiding a read from N64 SP_STATUS at 0xA4040010.
- Disabled verbose debug_printf context-switch output; runtime.log remains available.
- Preserved generated CPU code modifications in tools/recomp-runtime.patch.

Regenerate from the project root with `python tools/regenerate.py`, then run `build_game.bat`. The regeneration script fails if reviewed patches no longer apply; do not run N64Recomp alone and discard the patches.

Validation: regeneration and patch application succeeded; native build succeeded. Runtime test advances beyond the previous frame-2 stall, completes at least 20 fiber frames, and submits over 120 graphics display lists. This is boot/runtime validation, not a complete playthrough or an auditory check.
