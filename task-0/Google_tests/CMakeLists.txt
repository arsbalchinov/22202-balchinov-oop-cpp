project(Google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
enable_testing()
add_executable(Google_Tests_run
        FileReader_test.cpp
        ../FileReader.h
        ../FileReader.cpp
        Parser_test.cpp
        ../Parser.h
        ../Parser.cpp
        Stats_test.cpp
        ../Stats.h
        ../Stats.cpp
        FileWriter_test.cpp
        ../FileWriter.h
        ../FileWriter.cpp
        ../main.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)