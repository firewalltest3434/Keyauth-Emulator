# Keyauth Server Emulator
For educational purposes only. Use responsibly on your own programs to test them against these trivial methods.

## Usage
### Step 1: Obtain application secret
Example of doing so: [Click me](https://player.vimeo.com/video/1006943145?) 

you can use regex `^[a-zA-Z0-9]{64}$` to show only strings that match with the secret format. ( Proccess Hacker )

### Step 2: Run the emulator
Before you can use the emulator, you need to do two things:

**Add the generated root CA certificate to trusted root certificates**
1. Double-click on `rootCA.crt`
2. Click "Install certificate"
3. Select "Local Machine," then click "Next"
4. Select "Place all certificates in the following store," click "Browse" and select "Trusted Root Certification Authorities"
5. Click "Finish" ( only needed to do 1 time )

Same thing for `keyauth.win.crt` Certificate but Just pressing next works fine ( also 1 time also )

**Redirect API URLs to localhost using hosts file**
1. Open `C:\Windows\System32\drivers\etc\hosts`
2. Add the following line:
```
127.0.0.1 keyauth.win
127.0.0.1 keyauth.cc
they might use a custom domain so same thing for the custom domain
```

install [OpenSSL binary builds for Windows](https://kb.firedaemon.com/support/solutions/articles/4000121705#Download-OpenSSL).

**BEFORE STARTING MAKE SURE YOU HAVE THE CERTIFICATES INSTALLED AND THE FOLDER certs with all the files from the certificates**


**DONE**

Once that is done, open `EmuAuth.exe` and enter the application secret. All traffic to KeyAuth servers should now be redirected to it. You might need to recompile it and edit/add some other responses depending on the target program.

## Compiling
1. Download and install [OpenSSL binary builds for Windows](https://kb.firedaemon.com/support/solutions/articles/4000121705#Download-OpenSSL).
2. Make sure you have VS2022 with C++ build tools and MFC installed
3. Open `EmuAuth.sln` and compile the project (you may need to adjust include and library directories if you have choisen non-default install location for OpenSSL)
4. Generate required certificates using the script in `Certificates/` and place them in `certs/` folder next to the `EmuAuth.exe`

**Tipp** They are already generated but if they expire you would need to regenerate them!

## How to host the Emulator on a RDP

1. Get a Windows RDP
2. Install The Emulator on the RDP ( like u did on your PC )
3. Disable Firewall or let port 443 be enabled
4. Now just use instead of 127.0.0.1 in the hosts file the ip of the rdp

# Credits
github.com/SamuelTulach for Creating this

github.com/yerrroo for fixing it in his fork

I just updated it and added some more handling for keyauth applications etc
