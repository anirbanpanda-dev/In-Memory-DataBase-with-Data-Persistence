#include "DataProcessor.h"

DataProcessor* DataProcessor::processor = NULL;

DataProcessor::DataProcessor(){
    storageManager = new StorageManager();
}

DataProcessor* DataProcessor::getInstance(){
    // Add mutex lock for mutithreaded env
    if(!processor){
        processor = new DataProcessor();
    }
    return processor;
}

void DataProcessor::Start(){
    storageManager->Start();
}

void DataProcessor::AddData(std::string key, std::string value){
    try{
        if(key.length() == 0) throw new Exception("Null Key");
        storageManager->AddData(key, value);
    }
    catch(Exception* ex){
        std::cout << "Exception thrown with error " << ex->getErrorMsg()<<std::endl;
    }
    
}

void DataProcessor::Deletedata(std::string key){
    try{
        if(key.length() == 0) throw new Exception("Null Key");
        storageManager->Deletedata(key);
    }
    catch(Exception* ex){
        std::cout << "Exception thrown with error " << ex->getErrorMsg()<<std::endl;
    }
}

std::string DataProcessor::GetData(std::string key){
    std::string data = "";
    try{
        if(key.length() == 0) throw new Exception("Null Key");
        data = storageManager->GetData(key);
    }
    catch(Exception* ex){
        std::cout << "Exception thrown with error " << ex->getErrorMsg()<<std::endl;
    }
    return data;
}

