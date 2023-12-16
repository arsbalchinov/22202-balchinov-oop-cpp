project(Google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
enable_testing()
add_executable(Google_Tests_run
        Constructor_test.cpp
        Push_test.cpp
        Pop_test.cpp
        Insert_test.cpp
        Erase_test.cpp
        Index_test.cpp
        Linearize_test.cpp
        CapacityResize_test.cpp
        Swap_test.cpp
        ../CircularBuffer.h
        ../CircularBuffer.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)