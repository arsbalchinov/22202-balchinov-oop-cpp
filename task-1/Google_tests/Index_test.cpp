#include <gtest/gtest.h>
#include "../CircularBuffer.h"

TEST(Index, OperatorTest) {
    CircularBuffer<int> cb(3, 1);
    cb[1] = 10;
    cb[2] = cb[1];
    EXPECT_EQ(cb[0], 1);
    EXPECT_EQ(cb[1], 10);
    EXPECT_EQ(cb[2], 10);
}
TEST(Index, AtTest) {
    CircularBuffer<int> cb(3, 1);
    EXPECT_THROW(cb.at(-1), out_of_range);
    EXPECT_THROW(cb.at(5), out_of_range);
    EXPECT_THROW(cb.at(3), out_of_range);
    cb.at(1) = 5;
    EXPECT_EQ(cb.at(0), 1);
    EXPECT_EQ(cb.at(1), 5);
}
TEST(Index, FrontTest1) {
    CircularBuffer<int> cb(3, 1);
    EXPECT_EQ(cb.front(), 1);
    EXPECT_EQ(cb.at(1), 1);
}
TEST(Index, FrontTest2) {
    CircularBuffer<int> cb(3, 1);
    cb.front() = 5;
    EXPECT_EQ(cb.front(), 5);
    EXPECT_EQ(cb.at(1), 1);
}
TEST(Index, FrontTest3) {
    CircularBuffer<int> cb;
    EXPECT_THROW(cb.front(), out_of_range);
}
TEST(Index, BackTest1) {
    CircularBuffer<int> cb(3, 1);
    EXPECT_EQ(cb.at(1), 1);
    EXPECT_EQ(cb.back(), 1);
}
TEST(Index, BackTest2) {
    CircularBuffer<int> cb(3, 1);
    cb.back() = 10;
    EXPECT_EQ(cb.at(1), 1);
    EXPECT_EQ(cb.back(), 10);
}
TEST(Index, BackTest3) {
    CircularBuffer<int> cb;
    EXPECT_THROW(cb.back(), out_of_range);
}