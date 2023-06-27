@echo off
setlocal

set "url=https://github.com/DavidVuescu/DaDaism-Painter/releases/download/v1.0/app.zip"
set "outputPath=%TEMP%\app.zip"
set "extractTo=%userprofile%\Documents\.bciapps"

echo ===============================================================================
echo =========                  DaDa Painter Installation                  =========
echo ===============================================================================

curl -L -o "%outputPath%" "%url%"

if errorlevel 1 (
    echo Failed to download file.
    exit /b
) else (
    echo File downloaded successfully.
)

powershell -Command "Add-Type -A 'System.IO.Compression.FileSystem'; [IO.Compression.ZipFile]::ExtractToDirectory('%outputPath%', '%extractTo%')"

if errorlevel 1 (
    echo Failed to extract file.
    exit /b
) else (
    echo File extracted successfully.
)

endlocal
