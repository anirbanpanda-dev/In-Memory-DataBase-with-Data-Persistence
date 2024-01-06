#include "KeyValue.h"

KeyValue* KeyValue::kv = NULL;

KeyValue::KeyValue(){

}
    
KeyValue* KeyValue::getInstance(){
    if(!kv){
        kv = new KeyValue();
    }
    return kv;
}

void KeyValue::AddData(std::string key, std::string value, long identifier){
    
    kvMap[key] = {value, identifier};
}

std::string KeyValue::GetData(std::string key){
    if(kvMap.find(key)==kvMap.end()){
        return "";
    }
    return kvMap[key].first;
}

void KeyValue::Deletedata(std::string key, long identifier){
    if(kvMap.find(key)==kvMap.end()) throw ;
    kvMap.erase(key);
}