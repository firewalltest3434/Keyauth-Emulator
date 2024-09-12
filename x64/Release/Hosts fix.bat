@echo off
SETLOCAL ENABLEDELAYEDEXPANSION
title 0xbenz - Hosts Fixer

:: Define paths
set "hostsFilePath=%SystemRoot%\System32\drivers\etc\hosts"
set "newHostsEntry=127.0.0.1 keyauth.win"

:: Check for administrative privileges
openfiles >nul 2>&1 || (
    echo This script requires administrative privileges. Please run as administrator.
    exit /b 1
)

:: Backup original hosts file
copy "%hostsFilePath%" "%hostsFilePath%.old.file"

:: Remove keyauth.win entry
echo Removing keyauth.win entry...
findstr /v /c:"%newHostsEntry%" "%hostsFilePath%" > "%temp%\hosts.tmp"
copy "%temp%\hosts.tmp" "%hostsFilePath%" >nul
del "%temp%\hosts.tmp"

:: Inform user about the completion
msg * "The keyauth.win entry has been removed from your hosts file."

:: Script completion
echo Host entry removed successfully.
ENDLOCAL
