cmake_minimum_required(VERSION 3.12)
project(InMemoryDB)

set(CMAKE_CXX_STANDARD 11)

set(WORK_DIR "/Documents")

add_executable(InMemoryDB
                main.cpp
                Common.cpp
                DataLogger.cpp 
                DataProcessor.cpp 
                KeyValue.cpp 
                StorageManager.cpp 
                Test.cpp)
