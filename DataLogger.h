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
    void AddData(std::string key, std::string value, long identifier);
    void Deletedata(std::string key, long identifier);
    std::map<std::string, std::vector<std::string>> LoadPreviousData();
    void processLine(std::map<std::string, std::vector<std::string>>& updateMap, std::string line);
};