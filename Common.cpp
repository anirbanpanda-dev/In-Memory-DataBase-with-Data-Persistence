#include "Common.h"


Exception::Exception(std::string msg){
    errorMsg = msg;
}

std::string Exception::getErrorMsg(){
    return errorMsg;
}