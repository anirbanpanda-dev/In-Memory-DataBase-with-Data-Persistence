#pragma once 
#include "Common.h"
#include <fstream>

class DataLogger{
    static DataLogger* logger;
    DataLogger();
    std::ofstream OpenLoggerFileWriter();
    std::ifstream OpenLoggerFileReader();
    public:
    static DataLogger* getInstance();
    void AddData(std::string key, std::string value, std::time_t identifier);
    std::map<std::string, std::vector<std::string>> LoadPreviousData();
};