@echo off
echo Installing binary...
if not exist "C:\include" (
    mkdir "C:\include"
)
copy /y "binary.hpp" "C:\include\binary.hpp"
if %errorlevel% equ 0 (
    echo Installation successful! Add 'C:\include' to your compiler paths.
) else (
    echo Installation failed. Please run as Administrator.
)
pause