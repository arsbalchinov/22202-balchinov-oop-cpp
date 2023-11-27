cmake_minimum_required(VERSION 3.26)
project(task_0)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Google_tests)
add_executable(task_0 main.cpp
        FileReader.cpp
        FileReader.h
        FileWriter.cpp
        FileWriter.h
        Parser.cpp
        Parser.h
        Stats.cpp
        Stats.h)