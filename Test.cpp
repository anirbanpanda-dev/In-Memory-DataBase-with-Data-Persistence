#include "Test.h"


Test::Test(){

}

void Test::test01(){
    std::cout << DataProcessor::getInstance()->GetData("Anirban");
}

void Test::RunAllTests(){
    test01();
}