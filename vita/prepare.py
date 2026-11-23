"""Prepare isolated host sources for the Vita application."""
import argparse
from pathlib import Path
import shutil
import subprocess
import tempfile


VITA = Path(__file__).resolve().parent
ROOT = VITA.parent
RENDERER_URL = "https://github.com/SeveerJ/tnt64-recomp.git"
RENDERER_REV = "1460e3f2e29a9420358c92bd2492e7088d7e9e5d"
RUNTIME_REV = "e4342ae030a9d94aa97a81aafd3368ed7daa74df"


def git(directory, *args, capture=False):
    return subprocess.run(
        ["git", "-C", str(directory), *args],
        check=True,
        stdout=subprocess.PIPE if capture else None,
    ).stdout


def apply_patch(directory, patch):
    git(directory, "init", "--quiet")
    git(directory, "apply", "--ignore-space-change", str(patch))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--renderer-source", type=Path, help="Use an existing checkout of the pinned renderer")
    args = parser.parse_args()
    runtime = ROOT / "tools" / "N64ModernRuntime"
    if not (runtime / "N64Recomp" / "include" / "recomp.h").is_file():
        parser.error("Run tools/setup_dependencies.ps1 to initialize N64ModernRuntime first.")
    if git(runtime, "rev-parse", "HEAD", capture=True).decode().strip() != RUNTIME_REV:
        parser.error("The existing N64ModernRuntime checkout is at an unexpected revision.")

    output = ROOT / "build" / "vita-deps"
    output.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix="prepare-", dir=output) as temp:
        staging = Path(temp)
        renderer_repo = args.renderer_source
        if renderer_repo is None:
            renderer_repo = staging / "reference"
            renderer_repo.mkdir()
            git(renderer_repo, "init", "--quiet")
            git(renderer_repo, "fetch", "--depth=1", RENDERER_URL, RENDERER_REV)

        renderer = staging / "gles"
        renderer.mkdir()
        for name in ("n64_renderer.cpp", "n64_renderer.hpp"):
            data = git(renderer_repo, "show", f"{RENDERER_REV}:TNTRecomp/src/gles/{name}", capture=True)
            (renderer / name).write_bytes(data)
        license_data = git(renderer_repo, "show", f"{RENDERER_REV}:TNTRecomp/COPYING", capture=True)
        (renderer / "COPYING").write_bytes(license_data)
        apply_patch(renderer, VITA / "fast3d-renderer.patch")

        runtime_copy = staging / "runtime"
        runtime_copy.mkdir()
        shutil.copy2(runtime / "CMakeLists.txt", runtime_copy)
        for name in ("librecomp", "ultramodern", "N64Recomp", "thirdparty"):
            shutil.copytree(runtime / name, runtime_copy / name, ignore=shutil.ignore_patterns(".git", "build"))
        apply_patch(runtime_copy, VITA / "runtime.patch")

        for directory in (runtime_copy, renderer):
            shutil.copytree(directory, output / directory.name, dirs_exist_ok=True,
                            ignore=shutil.ignore_patterns(".git"))
    print(f"Prepared Vita runtime and renderer under {output}")


if __name__ == "__main__":
    main()
