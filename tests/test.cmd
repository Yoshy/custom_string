@echo off
echo Test with default "C" locale
echo =======================
type test_data.txt | ..\bin\revlex.exe

echo.
echo Test with "CP1251" locale
echo =======================
type test_data_1251.txt | ..\bin\revlex.exe Russian_Russia.1251

echo.
echo Test with "CP866" locale
echo =======================
type test_data_866.txt | ..\bin\revlex.exe Russian_Russia.866

pause
