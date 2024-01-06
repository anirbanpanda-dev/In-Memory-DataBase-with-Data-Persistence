#include "StorageManager.h"


StorageManager::StorageManager(){

}

long StorageManager::GetUniqueIdentifier(){
    auto currentTimePoint = std::chrono::system_clock::now();
    long currentTime = std::chrono::system_clock::to_time_t(currentTimePoint);

    return currentTime;
}

void StorageManager::AddData(std::string key, std::string value){
    std::cout << "StorageManager::AddData\n";
    long currentTime = GetUniqueIdentifier();
    // DataLogger::getInstance()->getLatestTimeStamp()
    KeyValue::getInstance()->AddData(key, value, currentTime);
    DataLogger::getInstance()->AddData(key, value, currentTime);
}

void StorageManager::Deletedata(std::string key){
    long currentTime = GetUniqueIdentifier();
    KeyValue::getInstance()->Deletedata(key, currentTime);
    DataLogger::getInstance()->Deletedata(key, currentTime);
    
}
std::string StorageManager::GetData(std::string key){
    std::string value = KeyValue::getInstance()->GetData(key);
    return value;
}

void StorageManager::Start(){
    std::cout << " St Start\n";
    std::map<std::string, std::vector<std::string>> updateMap = 
        DataLogger::getInstance()->LoadPreviousData();

    std::cout << " update size " << updateMap.size() << std::endl;
    
    for(auto it : updateMap){
        std::cout << " St Start " << it.first << std::endl;

        if(it.first == "ADD"){
            long currentTime = GetUniqueIdentifier();
            KeyValue::getInstance()->AddData(it.second[0], it.second[1], currentTime);
        }

        else if(it.first == "DELETE"){
            long currentTime = GetUniqueIdentifier();
            KeyValue::getInstance()->Deletedata(it.second[0], currentTime);
        }

    }
}