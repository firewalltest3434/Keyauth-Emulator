#pragma once

namespace Handler
{
    void HandleInit(const httplib::Params& data, const httplib::Request&, httplib::Response& res);
    void HandleLogin(const httplib::Params& data, const httplib::Request&, httplib::Response& res);
    void HandleCheckBlacklist(const httplib::Params& data, const httplib::Request&, httplib::Response& res);
    void HandleLicense(const httplib::Params& data, const httplib::Request&, httplib::Response& res);
    void HandleFile(const httplib::Params& data, const httplib::Request&, httplib::Response& res);
    void HandleSession(const httplib::Params& data, const httplib::Request&, httplib::Response& res);
    void HandleBan(const httplib::Params& data, const httplib::Request&, httplib::Response& res);
    void HandleVar(const httplib::Params& data, const httplib::Request&, httplib::Response& res);
    void HandleLog(const httplib::Params& data, const httplib::Request&, httplib::Response& res);
    void Handlewebhook(const httplib::Params& data, const httplib::Request&, httplib::Response& res);
    void HandleFetchShit(const httplib::Params& data, const httplib::Request&, httplib::Response& res);
    void Process(const httplib::Request&, httplib::Response& res);
}