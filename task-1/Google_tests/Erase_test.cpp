#include <gtest/gtest.h>
#include "../CircularBuffer.h"

TEST(Erase, EmptyTest) {
    CircularBuffer cb;
    EXPECT_THROW(cb.erase(0, 1), out_of_range);
}
TEST(Erase, WrongIndex) {
    CircularBuffer cb(3, 1);
    EXPECT_THROW(cb.erase(0, 4), out_of_range);
}
TEST(Erase, InvalidArgs) {
    CircularBuffer cb(3, 1);
    EXPECT_THROW(cb.erase(1, 0), invalid_argument);
}
TEST(Erase, EraseTest1) {
    CircularBuffer cb(10, 5);
    EXPECT_NO_THROW(cb.erase(3, 8));
}
TEST(Erase, EraseTest2) {
    CircularBuffer cb(10);
    for (int i = 0; i < 10; i++) {
        cb.push_back(i);
    }
    cb.erase(0, 9);
    EXPECT_EQ(cb.size(), 1);
    EXPECT_EQ(cb.front(), 9);
    EXPECT_EQ(cb.back(), 9);
}
TEST(Erase, EraseTest3) {
    CircularBuffer cb(10, 5);
    cb.erase(0, 10);
    EXPECT_EQ(cb.size(), 0);
}
TEST(Clear, EmptyTest) {
    CircularBuffer cb;
    cb.clear();
    EXPECT_EQ(cb.capacity(), 0);
    EXPECT_TRUE(cb.empty());
}
TEST(Clear, ClearTest1) {
    CircularBuffer cb(5, 1);
    cb.clear();
    EXPECT_TRUE(cb.empty());
}
TEST(Clear, ClearTest2) {
    CircularBuffer cb(10, 5);
    cb.clear();
    EXPECT_TRUE(cb.empty());
    cb.push_back(1);
    EXPECT_EQ(cb[0], 1);
    cb.push_front(2);
    EXPECT_EQ(cb[0], 2);
}
