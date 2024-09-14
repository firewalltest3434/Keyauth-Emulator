#include "Global.h"


std::string Utils::GenerateHMAC(const std::string& key, const std::string& message)
{
    std::stringstream result;

#define SHA256_HASH_SIZE 32
    std::vector<uint8_t> out(SHA256_HASH_SIZE);

    hmac_sha256(key.data(), key.size(), message.data(), message.size(), out.data(), out.size());

    for (uint8_t x : out)
        result << std::hex << std::setfill('0') << std::setw(2) << static_cast<int>(x);

    return result.str();
}

std::string Utils::GenerateRandomString(size_t length)
{
    const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const size_t characterCount = characters.length();

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, characterCount - 1);

    std::string randomString;
    randomString.reserve(length);

    for (size_t i = 0; i < length; ++i)
    {
        randomString += characters[distribution(generator)];
    }

    return randomString;
}