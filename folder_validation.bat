setlocal

set "folderPath=%userprofile%\Documents\.bciapps"

if not exist "%folderPath%" (
    echo Folder .bciapps does not exist, creating...
    mkdir "%folderPath%"
) else (
    echo Folder .bciapps already exists.
)

endlocal
pause
