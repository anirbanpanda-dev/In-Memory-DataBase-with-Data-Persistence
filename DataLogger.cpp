#include "DataLogger.h"

DataLogger* DataLogger::logger = NULL;

DataLogger::DataLogger(){
    
}

DataLogger* DataLogger::getInstance(){
    if(!logger){
        logger = new DataLogger();
    }

    return logger;
}

std::ofstream DataLogger::OpenLoggerFileWriter(){
    std::ofstream outputFile("Output.log", std::ios::app);
    if (!outputFile.is_open()) {
        throw new Exception("Error opening the file.");
    }
    return outputFile;
}

std::ifstream DataLogger::OpenLoggerFileReader(){
    std::ifstream logFile("Output.log");
    if (!logFile.is_open()) {
        throw new Exception("Error opening the file.");
    }
    return logFile;
}

void DataLogger::AddData(std::string key, std::string value, std::time_t identifier){
    std::ofstream outputfile = OpenLoggerFileWriter();
    outputfile << "ADD|" << key << "|" << value << "|" 
                << std::to_string(identifier) << std::endl;
}

void processLine(std::map<std::string, std::vector<std::string>>& updateMap, std::string line){
    std::string command;
    std::string word = "";
    for(int i = 0; i<line.length(); i++ ){
        if(line[i]=='|'){
            if(word.length()>0){
                if(command.length()==0){
                    command = word;
                }
                else{
                    updateMap[command].push_back(word);
                }
            }
            word = "";
        }
        else word+= line[i];
    }

    if(word.length()>0){
        updateMap[command].push_back(word);
    }
}

std::map<std::string, std::vector<std::string>>
        DataLogger::LoadPreviousData(){
    std::map<std::string, std::vector<std::string>> updateMap;
    std::ifstream inputFile = OpenLoggerFileReader();

    std::string line;
    while(std::getline(inputFile, line)){
        processLine(updateMap, line);
    }
    return updateMap;
}