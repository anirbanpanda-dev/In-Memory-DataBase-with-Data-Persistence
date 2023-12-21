#pragma once 
#include <iostream>
#include <string>
#include <map>
#include <vector>


class Exception{
    std::string errorMsg;
    public:
    Exception(std::string msg);
    std::string getErrorMsg();
};