@echo off
title Chopper Attack - PC Native Recompilation
cd /d "%~dp0"
echo ====================================================
echo    CHOPPER ATTACK - NATIVE PC RECOMPILATION
echo ====================================================
echo Starting ChopperAttack.exe...
ChopperAttack.exe
if %ERRORLEVEL% NEQ 0 (
    echo.
    echo Game exited with error code %ERRORLEVEL%.
    pause
)
