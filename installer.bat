@echo off
setlocal

echo Running Connect4 installer...
call batch\c4.bat

echo Running DaDa Painter installer...
call batch\da.bat

echo Running BrainStompers installer...
call batch\bs.bat

echo Running Travelink Around installer...
call batch\ta.bat

echo Running Neuro Arcade installer...
call batch\na.bat

echo Cleaning up...
call batch\clean.bat

echo All batch files executed.
pause
