#include "Global.h"
#include <windows.h>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void changehostfile(const std::string& ipAddress, const std::string& hostname) {
    const std::string hostsFilePath = "C:\\Windows\\System32\\drivers\\etc\\hosts";

    std::ifstream hostsFileRead(hostsFilePath);

    std::string line;
    std::string entryToFind = ipAddress + " " + hostname;
    bool exists = false;

    while (std::getline(hostsFileRead, line)) {
        line.erase(0, line.find_first_not_of(" \t\r\n"));
        line.erase(line.find_last_not_of(" \t\r\n") + 1);

        if (line == entryToFind) {
            exists = true;
            break;
        }
    }

    hostsFileRead.close();

    if (exists) {
        return;
    }

    std::ofstream hostsFileWrite(hostsFilePath, std::ios_base::app);

    if (!hostsFileWrite.is_open()) {
    }

    hostsFileWrite << ipAddress << " " << hostname << "\n";

    hostsFileWrite.close();

}

int main()
{
    SetConsoleTitleA("Keyauth Server emulator");

    Console::Title("Credits", "\nCreator: github.com/SamuelTulach\nFixer: github.com/yerrroo\nand me github.com/NotInnominate releasing it with updates");
    Console::Warning("IF YOU BOUGHT THIS IT MEANS YOU GOT SCAMMED !!\n");
    Global::Secret = Console::ReadInput("Application secret: ");
    printf("\n");

    if (!fs::exists("certs") || !fs::is_directory("certs")) {
        Console::Error("The 'certs' folder does not exist or is not in the same directory.");
        getchar();
    }

    if (Global::Secret.length() != 64)
    {
        Console::Error("Entered application secret has invalid length");
        getchar();
    }



    Console::Info("Starting fake auth server...\n");
    changehostfile("127.0.0.1", "keyauth.win");
    Sleep(500);
    Console::Info("Open now the Keyauth Loader...\n");
    httplib::SSLServer svr("./certs/keyauth.win.crt", "./certs/keyauth.win.key");

    svr.Get("/ping", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("pong", "text/plain");
        });

    svr.Post("/api/1.2/", Handler::Process);

    svr.set_logger([](const httplib::Request& req, const httplib::Response& res) {
        Console::Debug("Request from %s at %s", req.remote_addr.c_str(), req.path.c_str());
        });

    bool status = svr.listen("127.0.0.1", 443);
    if (!status)
    {
        system("cls");
        printf("\n\n\n");
        Console::Error("ERROR :( CODE 69 MEANING I CAN'T LISTEN ON PORT 443");
        getchar();
    }

    getchar();
}