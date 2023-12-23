cmake_minimum_required(VERSION 3.26)
project(task_1)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Google_tests)
add_executable(task_1 main.cpp
        CircularBuffer.h
        CircularBuffer.cpp)