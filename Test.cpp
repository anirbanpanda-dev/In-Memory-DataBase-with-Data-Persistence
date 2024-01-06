#include "Test.h"


Test::Test(){

}

void Test::test01(){
    DataProcessor::getInstance()->AddData("Anirban", "1X100");
    std::cout << DataProcessor::getInstance()->GetData("Anirban") << std::endl;
}

void Test::test02(){
    std::string value = DataProcessor::getInstance()->GetData("Anirban");
    std::cout << value<< std::endl;
}

void Test::test03(){
    DataProcessor::getInstance()->Deletedata("Anirban");
    // std::cout << DataProcessor::getInstance()->GetData("Anirban");
}

void Test::RunAllTests(){
    test01();
    test03();
    test02();
}