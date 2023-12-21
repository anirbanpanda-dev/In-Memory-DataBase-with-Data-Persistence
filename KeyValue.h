#include "Common.h"
#include <map>
#include <vector>


class KeyValue{
    static KeyValue* kv;
    std::map<std::string, std::pair<std::string, std::time_t>> kvMap;
    KeyValue();
    public:
    static KeyValue* getInstance();
    void AddData(std::string key, std::string value, std::time_t identifier);
    std::string GetData(std::string key);
};