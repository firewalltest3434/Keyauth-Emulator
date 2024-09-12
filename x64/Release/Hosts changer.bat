@echo off
SETLOCAL ENABLEDELAYEDEXPANSION
title Hosts changer

:: Define paths
set "hostsFilePath=%SystemRoot%\System32\drivers\etc\hosts"
set "newHostsEntry=127.0.0.1 keyauth.win"

:: Check for administrative privileges
openfiles >nul 2>&1 || (
    echo This script requires administrative privileges. Please run as administrator.
    exit /b 1
)

:: Modify hosts file
echo Modifying hosts file...
echo %newHostsEntry% >> "%hostsFilePath%"

:: Inform user about removal option
msg * "The keyauth.win entry has been added to your hosts file. If you want to remove it, please run 'hosts fixer.bat'."


:: Script completion
echo Host entry added successfully.
ENDLOCAL
