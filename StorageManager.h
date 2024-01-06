#pragma once 
#include "Common.h"
#include "KeyValue.h"
#include "DataLogger.h"


class StorageManager{
    long GetUniqueIdentifier();
    public:
    StorageManager();
    void AddData(std::string key, std::string value);
    void Deletedata(std::string key);
    std::string GetData(std::string value);
    void Start();
};