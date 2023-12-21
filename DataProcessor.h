#pragma once 
#include "Common.h"
#include "StorageManager.h"


class DataProcessor{
    static DataProcessor* processor;
    StorageManager* storageManager;
    DataProcessor();
    public : 
    static DataProcessor* getInstance();
    void AddData(std::string key, std::string value);
    void Deletedata(std::string key);
    std::string GetData(std::string value);
    void Start();
};