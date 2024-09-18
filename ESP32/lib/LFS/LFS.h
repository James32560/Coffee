#include <LittleFS.h>
#include <ArduinoJson.h>
#include <vector>
#define FORMAT_LITTLEFS_IF_FAILED true

#include <HardwareSerial.h>

class LFS
{
public:
    LFS();

    void init();

    void saveJSON(String name, std::vector<float> time, std::vector<float> temp);
};