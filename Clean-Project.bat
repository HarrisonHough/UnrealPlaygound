@ECHO OFF

echo Unreal Cleanup Script
echo Client directory: %~dp0
pushd "%~dp0"

@RD /S /Q "Intermediate"
@RD /S /Q "Binaries"
@RD /S /Q "DerivedDataCache"
:: Deletes saved source control settings
@RD /S /Q "Saved"
del /S *.sln

:: Automatically clean plugins without asking
for /d %%a in (
    "Plugins\*"
) do if exist "%%~fa\Intermediate\" rmdir /s /q "%%~fa\Intermediate" & if exist "%%~fa\Binaries\" rmdir /s /q "%%~fa\Binaries"

for /d %%a in (
    "Plugins\Developer\*"
) do if exist "%%~fa\Intermediate\" rmdir /s /q "%%~fa\Intermediate" & if exist "%%~fa\Binaries\" rmdir /s /q "%%~fa\Binaries"

echo Project cleaned
echo Exiting