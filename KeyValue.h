#include "Common.h"
#include <map>
#include <vector>


class KeyValue{
    static KeyValue* kv;
    std::map<std::string, std::pair<std::string, long>> kvMap;
    KeyValue();
    public:
    static KeyValue* getInstance();
    void AddData(std::string key, std::string value, long identifier);
    std::string GetData(std::string key);
    void Deletedata(std::string key, long identifier);
};