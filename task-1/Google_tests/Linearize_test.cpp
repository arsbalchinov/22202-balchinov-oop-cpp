#include <gtest/gtest.h>
#include "../CircularBuffer.h"

TEST(Linearize, EmptyTest) {
    CircularBuffer cb;
    EXPECT_EQ(cb.linearize(), nullptr);
}
TEST(Linearize, LinearizeTest) {
    CircularBuffer cb(5, 1);
    cb.push_back(3);    //3(tail), 1(head), 1, 1, 1
    char* arr = cb.array();
    EXPECT_EQ(arr[0], 3);
    EXPECT_EQ(arr[1], 1);
    EXPECT_FALSE(cb.is_linearized());
    cb.linearize();          //1(head), 1, 1, 3(tail)
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[4], 3);
    EXPECT_TRUE(cb.is_linearized());
}
TEST(Linearize, ConstLinearizeTest) {
    const CircularBuffer cb(5, 1);
    const char* arr = cb.array();
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(arr[i], 1);
    }
    EXPECT_TRUE(cb.is_linearized());
}
TEST(Rotate, WrongBegin1) {
    CircularBuffer cb(5);
    EXPECT_THROW(cb.rotate(0), out_of_range);
}
TEST(Rotate, WrongBegin2) {
    CircularBuffer cb(5, 0);
    cb.pop_back();
    EXPECT_THROW(cb.rotate(4), out_of_range);
}
TEST(Rotate, RotateTest3) {
    CircularBuffer cb(10);
    for (int i = 0; i < 10; i++) {
        cb.push_back((char)i);
    }
    cb.rotate(4);
    EXPECT_EQ(cb.front(), 4);
    EXPECT_EQ(cb.back(), 3);
}