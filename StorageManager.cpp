#include "StorageManager.h"


StorageManager::StorageManager(){

}

std::time_t StorageManager::GetUniqueIdentifier(){
    auto currentTimePoint = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(currentTimePoint);

    return currentTime;
}

void StorageManager::AddData(std::string key, std::string value){
    std::time_t currentTime = GetUniqueIdentifier();
    // DataLogger::getInstance()->getLatestTimeStamp()
    KeyValue::getInstance()->AddData(key, value, currentTime);
    DataLogger::getInstance()->AddData(key, value, currentTime);
}

void StorageManager::Deletedata(std::string key){
    // KeyValue::getInstance()->Deletedata(key, currentTime);
    // DataLogger::getInstance()->Deletedata(key, currentTime);
    
}
std::string StorageManager::GetData(std::string key){
    std::string value = KeyValue::getInstance()->GetData(key);
    return value;
}

void StorageManager::Start(){
    std::map<std::string, std::vector<std::string>> updateMap = 
        DataLogger::getInstance()->LoadPreviousData();
    
    for(auto it : updateMap){

        if(it.first == "ADD"){
            std::time_t currentTime = GetUniqueIdentifier();
            KeyValue::getInstance()->AddData(it.second[0], it.second[1], currentTime);
        }

        else if(it.first == "DELETE"){
            // std::time_t currentTime = GetUniqueIdentifier();
            // KeyValue::getInstance()->AddData(it.second[0], it.second[1], currentTime);
        }

    }
}