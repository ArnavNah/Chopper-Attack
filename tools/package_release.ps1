# Automated Packaging Script for Chopper Attack
param (
    [string]$OutputDir = "package"
)

$ErrorActionPreference = "Stop"

Write-Host "== Packaging Chopper Attack Release ==" -ForegroundColor Cyan

if (-not (Test-Path "build\ChopperAttack.exe")) {
    Write-Error "build\ChopperAttack.exe not found! Please build the project first."
}

New-Item -ItemType Directory -Force -Path $OutputDir | Out-Null
New-Item -ItemType Directory -Force -Path "$OutputDir\rom" | Out-Null

Copy-Item -Force "build\ChopperAttack.exe" "$OutputDir\ChopperAttack.exe"
Copy-Item -Force "build\SDL2.dll" "$OutputDir\SDL2.dll"
Copy-Item -Force "build\dxcompiler.dll" "$OutputDir\dxcompiler.dll"
Copy-Item -Force "build\dxil.dll" "$OutputDir\dxil.dll"

Write-Host "Package assembled at: $OutputDir" -ForegroundColor Green
Get-ChildItem $OutputDir | Select-Object Name, Length
