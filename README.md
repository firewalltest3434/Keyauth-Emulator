## <a id="features"></a>📋・Information
```
The Keyauth Emulator can simulate nearly all aspects of Keyauth, including:

Full simulation of the initialization process, including the login system.
Features such as logs, bans, and blacklists are disabled
With this project, you can effectively run Keyauth-based applications Selfhosted 

DISCLAIMER:

This tool is intended solely for educational purposes,
such as learning how Keyauth works. 
Use it only on applications that you own or have explicit permission to use.
```

# End of support

Hi everyone, this project is finished. I don't think anything more is needed as the Only problem is that Variables or Files can't be accessed from keyauth servers which will never possible regardless.

Once again thx to github.com/SamuelTulach for creating it and yeah

Have fun, btw don't dare to dm me about help or i will just block your ass

# You can do any pull requests, i'll check them and approve or disapprove then

<details>
  <summary>Click me for the Usage Tutorial</summary>
  
## <a id="Changelog"></a>🔥・Usage Tutorial
```
Step 1: Setup everything
Add the generated root CA certificate to trusted root certificates

Double-click on rootCA.crt
Click "Install certificate"
Select "Local Machine," then click "Next"
Select "Place all certificates in the following store," click "Browse" and select "Trusted Root Certification"
Click "Finish" ( only needed to do 1 time )
Same thing for keyauth.win.crt Certificate but Just pressing next works fine ( also 1 time also )

Both of them are in the Folder x64/Release/certs

Now please install the OpenSSL 3.3.2 Windows Installer. 
https://kb.firedaemon.com/support/solutions/articles/4000121705#Download-OpenSSL

Step 2: Obtain application secret
Example of doing so: https://player.vimeo.com/video/1006943145

you can use regex ^[a-zA-Z0-9]{64}$ to show only strings that match with the secret format.

Step 3: Run it

Once everything is done run Emulator.exe.

if everything worked fine and you got no errors then procced to open the Keyauth Loader
```
</details>

<details>
  <summary>Click me for the Compiling Tutorial</summary>

## <a id="Changelog"></a>👷・Compiling
```
1. install the OpenSSL 3.3.2 Windows Installer. 
https://kb.firedaemon.com/support/solutions/articles/4000121705#Download-OpenSSL
2. Make sure you have VS2022 with C++ build tools and MFC installed
3. Open `EmuAuth.sln` and compile the project
4. Generate required certificates using the script in `Certificates/` and place them in `certs/`

**Tipp** They are already generated but if they expire you would need to regenerate them!
```
</details>

<details>
  <summary>Click me for the Remote Hosting </summary>

## <a id="Changelog"></a>🖥️・How to host the Emulator on a RDP
```
1. Get a Windows RDP
2. Recompile the Emulator with the server IP instead of 127.0.0.1
3. Install The Emulator on the RDP ( like u did on your PC )
4. Disable Firewall or let port 443 be enabled
5. Now just use instead of 127.0.0.1 in the hosts file the ip of the rdp
```
</details>

