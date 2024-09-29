#include "Global.h"
#include <windows.h>
#include <iostream>
#include <filesystem>
#include <httplib.h>
#include <sstream>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>

namespace fs = std::filesystem;
using json = nlohmann::json;

bool fetchSecretsFromPastebin(const std::string& url, std::unordered_map<std::string, std::string>& secrets) {
    httplib::Client cli("https://pastebin.com");
    auto res = cli.Get("/raw/3BAjRrjL"); 

    if (res && res->status == 200) {
        json j = json::parse(res->body); 
        for (const auto& item : j["secrets"].items()) {
            secrets[item.key()] = item.value(); 
        }
        return true;
    }
    else {
        std::cerr << "Failed to fetch secrets from Pastebin." << std::endl;
        return false;
    }
}


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

int main() {
    SetConsoleTitleA("Keyauth Server emulator");

    Console::Title("Credits", "\nCreator: github.com/SamuelTulach\nFixer: github.com/yerrroo\nand me github.com/NotInnominate releasing it with updates");
    Console::Warning("IF YOU BOUGHT THIS IT MEANS YOU GOT SCAMMED !!\n");

    if (!fs::exists("certs") || !fs::is_directory("certs")) {
        Console::Error("The 'certs' folder does not exist or is not in the same directory.");
        getchar();
    }

    std::cout << "What method do you want to use:\n\n";
    std::cout << "1. Online\n";
    std::cout << "2. Manual\n\n";
    std::string mode = Console::ReadInput("Enter your choice (1 or 2): ");

    if (mode == "1") {
        system("cls");
        printf("\n");

        std::unordered_map<std::string, std::string> secrets; 
        if (fetchSecretsFromPastebin("https://pastebin.com/raw/3BAjRrjL", secrets)) { 
            std::cout << "All Online Secrets:\n\n";
            int index = 1;
            for (const auto& secret : secrets) {
                std::cout << index++ << ". " << secret.first << ": " << secret.second << "\n"; 
            }

            printf("\n");
            std::string choice = Console::ReadInput("Choose which secret you want: ");
            int secretIndex = std::stoi(choice) - 1; 

            if (secretIndex >= 0 && secretIndex < secrets.size()) {
                auto it = secrets.begin();
                std::advance(it, secretIndex); 
                Global::Secret = it->second; 
                printf("\n");
            }
            else {
                Console::Error("Invalid choice. Please select a valid secret number.");
                getchar();
                return 1;
            }
        }
        else {
            return 1; 
        }
    }
    else if (mode == "2") {
        system("cls");
        printf("\n");
        Global::Secret = Console::ReadInput("Application secret: ");
        printf("\n");

        if (Global::Secret.length() != 64) {
            Console::Error("Entered application secret has invalid length");
            getchar();
        }
    }
    else {
        Console::Error("Invalid selection. Please enter '1' for Online or '2' for Manual.");
        getchar();
        return 1;
    }

    system("cls");
    printf("\n");
    Console::Info("Starting fake auth server...\n");
    changehostfile("127.0.0.1", "keyauth.win");
    Sleep(500);
    Console::Info("Open now the Keyauth Loader...\n");
    httplib::SSLServer svr("./certs/keyauth.win.crt", "./certs/keyauth.win.key");

    svr.Get("/ping", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("pong", "text/plain");
        });

    svr.Post("/api/1.2/", Handler::Process);
    svr.Post("/api/1.1/", Handler::Process);

    svr.set_logger([](const httplib::Request& req, const httplib::Response& res) {
        Console::Debug("Request from %s at %s", req.remote_addr.c_str(), req.path.c_str());
        });

    bool status = svr.listen("127.0.0.1", 443);
    if (!status) {
        system("cls");
        printf("\n\n\n");
        Console::Error("ERROR :( CODE 69 MEANING I CAN'T LISTEN ON PORT 443");
        getchar();
    }

    getchar();
}