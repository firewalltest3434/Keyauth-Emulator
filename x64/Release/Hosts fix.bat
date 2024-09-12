@echo off
setlocal enabledelayedexpansion

set entry_to_remove=127.0.0.1 keyauth.win

set temp_file=%TEMP%\hosts_temp

if not exist C:\Windows\System32\drivers\etc\hosts (
    echo Hosts file not found!
    exit /b
)

for /f "tokens=*" %%A in (C:\Windows\System32\drivers\etc\hosts) do (
    set line=%%A
    if "!line!" neq "%entry_to_remove%" (
        echo %%A >> %temp_file%
    )
)

move /Y %temp_file% C:\Windows\System32\drivers\etc\hosts

echo Entry removed if it existed.
