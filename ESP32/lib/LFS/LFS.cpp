#include <LFS.h>

LFS::LFS() {}

void LFS::init()
{
    LittleFS.begin(FORMAT_LITTLEFS_IF_FAILED);
}

void LFS::saveJSON(String name, std::vector<float> time, std::vector<float> temp)
{
    JsonDocument doc;
    
    doc["name"] = "temp";
}