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

void KeyValue::AddData(std::string key, std::string value, std::time_t identifier){
    kvMap[key] = {value, identifier};
}

std::string KeyValue::GetData(std::string key){
    if(kvMap.find(key)==kvMap.end()){
        return "";
    }
    return kvMap[key].first;
}