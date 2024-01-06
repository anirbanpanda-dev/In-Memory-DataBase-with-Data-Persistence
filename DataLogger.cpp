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
        throw new Exception("Error opening the file for Writing.");
    }
    return outputFile;
}

std::ifstream DataLogger::OpenLoggerFileReader(){
    std::cout << "OpenLoggerFileReader\n";
    std::ifstream logFile("Output.log");
    if (!logFile.is_open()) {
        std::ofstream outputFile("Output.log", std::ios::app);
        outputFile.close();
        std::ifstream logFile("Output.log");
        // throw new Exception("Error opening the file for Reading.");
    }
    return logFile;
}

void DataLogger::AddData(std::string key, std::string value, long identifier){
    std::ofstream outputfile = OpenLoggerFileWriter();
    outputfile << "ADD|" << key << "|" << value << "|" 
                << std::to_string(identifier) << std::endl;
}

void DataLogger::Deletedata(std::string key, long identifier){
    std::cout << "DataLogger::Deletedata\n";
    std::ofstream outputfile = OpenLoggerFileWriter();
    outputfile << "DELETE|" << key << "|" 
                << std::to_string(identifier) << std::endl;
}

void DataLogger::processLine(std::map<std::string, std::vector<std::string>>& updateMap, std::string line){
    std::cout << " processLine \n";
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
    std::cout << " LoadPreviousData \n";
    std::map<std::string, std::vector<std::string>> updateMap;
    std::ifstream inputFile = OpenLoggerFileReader();

    std::string line;
    while(std::getline(inputFile, line)){
        processLine(updateMap, line);
    }
    inputFile.close();
    return updateMap;
}