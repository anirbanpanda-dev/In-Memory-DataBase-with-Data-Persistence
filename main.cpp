#include "Common.h"
#include "DataProcessor.h"
#include "Test.h"
#include <unistd.h>



int main(){
    DataProcessor::getInstance()->Start();
    Test* test = new Test();
    test->RunAllTests();
}