#pragma once

namespace Utils
{
    std::string GenerateHMAC(const std::string& key, const std::string& message);
    std::string GenerateRandomString(size_t length);
}