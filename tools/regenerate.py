"""Regenerate native code and reapply reviewed runtime edits. Run from project root."""
from pathlib import Path
import subprocess
import sys
root = Path(__file__).resolve().parent.parent
subprocess.run([str(root / "tools/N64Recomp/build/N64Recomp.exe"), "chopper.toml"], cwd=root, check=True)
subprocess.run(["git", "apply", "--check", "tools/recomp-runtime.patch"], cwd=root, check=True)
subprocess.run(["git", "apply", "tools/recomp-runtime.patch"], cwd=root, check=True)
subprocess.run([str(root / "tools/N64Recomp/build/RSPRecomp.exe"), "aspMain.toml"], cwd=root, check=True)
print("Generated CPU and audio code; runtime patches applied.")
