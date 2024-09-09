#include "Global.h"

void Handler::HandleInit(const httplib::Params& data, const httplib::Request&, httplib::Response& res)
{
    Console::Info("Handling API INIT request...");

    std::string clientKey = data.find("enckey")->second;
    Console::Debug("Encryption key: %s", clientKey.c_str());
 
    Global::EncryptionKey = clientKey + "-" + Global::Secret;

    nlohmann::json output = {
      {"success", true},
      {"message", "Initialized"},
      {"sessionid", "emulatedlol"},
      {"appinfo", {
        {"numUsers", "N/A"},
        {"numOnlineUsers", "N/A"},
        {"numKeys", "N/A"},
        {"version", "1.1"},
        {"customerPanelLink", "https://keyauth.cc/panel/xxx"},
      }},
      {"newSession", true},
      {"nonce", "feeddead"}
    };

    std::string json = output.dump();
    std::string checksum = Utils::GenerateHMAC(Global::Secret, json);

    Console::Debug("Using signature: %s", checksum.c_str());
    Console::Debug("JSON: %s", json.c_str());

    res.set_header("signature", checksum);
    res.set_content(json, "application/json");

    Console::Success("INIT request handled");
}

void Handler::HandleLogin(const httplib::Params& data, const httplib::Request&, httplib::Response& res)
{
    Console::Info("Handling API LOGIN request...");

    std::string username = data.find("username")->second;
    Console::Debug("Username: %s", username.c_str());

    nlohmann::json output = 
    {
    {"success", true},
    {"message", "Logged in!"},
    {"info", 
        {
                {"username", "Kollegah"},
                {"subscriptions", {{
                    {"subscription", "Gta6Premium"},
                    {"key", "T3RpIG1ha2UgdGhpcyBzaGl0IHdvcms="}, // ;)
                    {"expiry", "2031259554"},
                    {"timeleft", 315569071}
                }}},
                {"ip", "88.88.88.88"},
                {"hwid", "FBI-GOVERMENT-PC"},
                {"createdate", "6942010069"},
                {"lastlogin", "9876543210"}
    }},
                {"nonce", "feeddead"}
    };

    std::string json = output.dump();
    std::string checksum = Utils::GenerateHMAC(Global::EncryptionKey, json);

    Console::Debug("Using signature: %s", checksum.c_str());
    Console::Debug("JSON: %s", json.c_str());

    res.set_header("signature", checksum);
    res.set_content(json, "application/json");

    Console::Success("LOGIN request handled");
}

void Handler::HandleCheckBlacklist(const httplib::Params& data, const httplib::Request&, httplib::Response& res)
{
    Console::Info("Handling API CHECKBLACKLIST request...");

    std::string hwid = data.find("hwid")->second;
    std::string sessionId = data.find("sessionid")->second;
    Console::Debug("HWID: %s", hwid.c_str());
    Console::Debug("Session ID: %s", sessionId.c_str());

  
    bool isBlacklisted = false;

    nlohmann::json output;
    if (isBlacklisted)
    {
        output = 
        {
            {"success", true},
            {"message", "Client is blacklisted"},
            {"nonce", Utils::GenerateRandomString(32)}
        };
    }

    else
    {
        output = 
        {
            {"success", false},
            {"message", "Client is not blacklisted"}
        };
    }

    std::string json = output.dump();
    std::string checksum = Utils::GenerateHMAC(Global::EncryptionKey, json);

    Console::Debug("Using signature: %s", checksum.c_str());
    Console::Debug("JSON: %s", json.c_str());

    res.set_header("signature", checksum);
    res.set_content(json, "application/json");

    Console::Success("CHECKBLACKLIST request handled");
}

void Handler::HandleLicense(const httplib::Params& data, const httplib::Request&, httplib::Response& res)
{
    Console::Info("Handling API LICENSE request...");

    std::string licenseKey = data.find("key")->second;
    std::string hwid = data.find("hwid")->second;
    std::string sessionId = data.find("sessionid")->second;
    Console::Debug("License Key: %s", licenseKey.c_str());
    Console::Debug("HWID: %s", hwid.c_str());
    Console::Debug("Session ID: %s", sessionId.c_str());

    bool isLicenseValid = true;

    nlohmann::json output;
    if (isLicenseValid)
    {
        output = 
        {
            {"success", true},
            {"message", "License is valid"},
            {"info", 
            {
                {"username", "Kollegah"},
                {"subscriptions", {{
                    {"subscription", "Gta6Premium"},
                    {"key", "T3RpIG1ha2UgdGhpcyBzaGl0IHdvcms="}, // pls
                    {"expiry", "2031259554"},
                    {"timeleft", 315569071}
                }}},
                {"ip", "88.88.88.88"},
                {"hwid", "FBI-GOVERMENT-PC"},
                {"createdate", "6942010069"},
                {"lastlogin", "9876543210"}
            }},
            {"nonce", Utils::GenerateRandomString(32)}
        };
    }
    else
    {
        output = 
        {
            {"success", false},
            {"message", "Invalid license"}
        };
    }

    std::string json = output.dump();
    std::string checksum = Utils::GenerateHMAC(Global::EncryptionKey, json);

    Console::Debug("Using signature: %s", checksum.c_str());
    Console::Debug("JSON: %s", json.c_str());

    res.set_header("signature", checksum);
    res.set_content(json, "application/json");

    Console::Success("LICENSE request handled");
}

void Handler::HandleSession(const httplib::Params& data, const httplib::Request&, httplib::Response& res)
{
    Console::Info("Handling API Session Check...");

    std::string sessionId = data.find("sessionid")->second;
    Console::Debug("Session ID: %s", sessionId.c_str());

    nlohmann::json output =
    {
    {"success", true},
    {"message", "I am real gangster!"},
    };

    std::string json = output.dump();
    std::string checksum = Utils::GenerateHMAC(Global::EncryptionKey, json);

    Console::Debug("Using signature: %s", checksum.c_str());
    Console::Debug("JSON: %s", json.c_str());

    res.set_header("signature", checksum);
    res.set_content(json, "application/json");

    Console::Success("Session Check request handled");
}

void Handler::HandleVar(const httplib::Params& data, const httplib::Request&, httplib::Response& res)
{
    Console::Info("Handling API Var Check...");

    std::string sessionId = data.find("sessionid")->second;
    Console::Debug("Session ID: %s", sessionId.c_str());

    nlohmann::json output =
    {
    {"success", true},
    {"message", "idk"},
    {"nonce", Utils::GenerateRandomString(32)}
    };

    std::string json = output.dump();
    std::string checksum = Utils::GenerateHMAC(Global::EncryptionKey, json);

    Console::Debug("Using signature: %s", checksum.c_str());
    Console::Debug("JSON: %s", json.c_str());

    res.set_header("signature", checksum);
    res.set_content(json, "application/json");

    Console::Success("Var shit handled");
}

void Handler::HandleLog(const httplib::Params& data, const httplib::Request&, httplib::Response& res)
{
    Console::Info("Handling Log Check...");

    std::string sessionId = data.find("sessionid")->second;
    Console::Debug("Session ID: %s", sessionId.c_str());

    nlohmann::json output =
    {
    {"success", true},
    {"message", "No logs for me hehehe"},
    };

    std::string json = output.dump();
    std::string checksum = Utils::GenerateHMAC(Global::EncryptionKey, json);

    Console::Debug("Using signature: %s", checksum.c_str());
    Console::Debug("JSON: %s", json.c_str());

    res.set_header("signature", checksum);
    res.set_content(json, "application/json");

    Console::Success("Log request handled");
}

void Handler::HandleBan(const httplib::Params& data, const httplib::Request&, httplib::Response& res)
{
    Console::Info("Handling API Ban request ...");

    std::string sessionId = data.find("sessionid")->second;
    Console::Debug("Session ID: %s", sessionId.c_str());

    nlohmann::json output =
    {
    {"success", false},
    {"message", "Nuh uh!"},
    };

    std::string json = output.dump();
    std::string checksum = Utils::GenerateHMAC(Global::EncryptionKey, json);

    Console::Debug("Using signature: %s", checksum.c_str());
    Console::Debug("JSON: %s", json.c_str());

    res.set_header("signature", checksum);
    res.set_content(json, "application/json");

    Console::Success("Session Check request handled");
}


void Handler::HandleFile(const httplib::Params& data, const httplib::Request&, httplib::Response& res)
{
    Console::Info("Handling API FILE request...");

    std::string fileId = data.find("fileid")->second;
    std::string sessionId = data.find("sessionid")->second;
    Console::Debug("File ID: %s", fileId.c_str());
    Console::Debug("Session ID: %s", sessionId.c_str());

   
    bool isFileFound = true;
    bool requiresAuth = true;
    bool isSessionValidated = true;
    std::string fileContent = "GIMMME THE LOOT";

    nlohmann::json output;
    if (!isFileFound)
    {
        output = 
        {
            {"success", false},
            {"message", "File not found"}
        };
    }
    else if (requiresAuth && !isSessionValidated)
    {
        output = 
        {
            {"success", false},
            {"message", "Session unauthorized"}
        };
    }
    else
    {
        output = 
        {
            {"success", true},
            {"message", "File found"},
            {"content", fileContent},
            {"nonce", Utils::GenerateRandomString(32)}
        };
    }

    std::string json = output.dump();
    std::string checksum = Utils::GenerateHMAC(Global::EncryptionKey, json);

    Console::Debug("Using signature: %s", checksum.c_str());
    Console::Debug("JSON: %s", json.c_str());

    res.set_header("signature", checksum);
    res.set_content(json, "application/json");

    Console::Success("FILE request handled");
}

void Handler::Process(const httplib::Request& req, httplib::Response& res)
{
    httplib::Params data;
    httplib::detail::parse_query_text(req.body, data);

    Console::Debug("Request has %i parameters with body %s", data.size(), req.body.c_str());

    std::string type = data.find("type")->second;

    if (type == "init")
    {
        HandleInit(data, req, res);
        return;
    }

    if (type == "login")
    {
        HandleLogin(data, req, res);
        return;
    }

    if (type == "checkblacklist")
    {
        HandleCheckBlacklist(data, req, res);
        return;
    }

    if (type == "license")
    {
        HandleLicense(data, req, res);
        return;
    }

    if (type == "file")
    {
        HandleFile(data, req, res);
        return;
    }

    if (type == "check")
    {
        HandleSession(data, req, res);
        return;
    }

    if (type == "log")
    {
        HandleLog(data, req, res);
        return;
    }

    if (type == "var")
    {
        HandleVar(data, req, res);
        return;
    }

    Console::Error("Unknown API request type");
}
