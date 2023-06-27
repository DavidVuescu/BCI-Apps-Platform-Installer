@echo off
setlocal

set "outputPath=%TEMP%\app.zip"

del "%outputPath%"

if errorlevel 1 (
    echo Failed to delete file.
) else (
    echo File deleted successfully.
)

endlocal
