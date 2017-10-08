@echo off
IF [%VisualStudioVersion%]==[] (
    ECHO Thou shalt run this script from Visual Studio's 'x86 Native Tools Command Prompt'!
    GOTO:eof
)
SET CONFIG=Release
SET BUILDDIR=build_win32

rmdir /s /q %BUILDDIR%
mkdir %BUILDDIR%
cd %BUILDDIR%
cmake -A Win32 -G "Visual Studio 14 2015" ../src
cmake --build . --config %CONFIG%
cmake --build . --target install --config %CONFIG%

SET CEC=cmake -E cmake_echo_color --green
if %ERRORLEVEL% EQU 0 (
    %CEC% "========================================"
    %CEC% "Build completed."
    %CEC% "Look for executables in bin directory"
    %CEC% "========================================"
)
cd ..
