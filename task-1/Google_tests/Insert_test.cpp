#include <gtest/gtest.h>
#include "../CircularBuffer.h"

TEST(Insert, EmptyTest) {
    CircularBuffer cb;
    EXPECT_THROW(cb.insert(0, 1), out_of_range);
}
TEST(Insert, InsertTest1) {
    CircularBuffer cb(3);
    EXPECT_THROW(cb.insert(5, 1), out_of_range);
}
TEST(Insert, InsertTest2) {
    CircularBuffer cb(3);
    EXPECT_NO_THROW(cb.insert(0, 1));
    EXPECT_EQ(cb.capacity(), 3);
    EXPECT_EQ(cb.size(), 1);
    EXPECT_EQ(cb.back(), 1);
    EXPECT_EQ(cb.front(), 1);
}
TEST(Insert, InsertTest3) {
    CircularBuffer cb(3);
    cb.insert(0, 1);
    EXPECT_FALSE(cb.empty());
    EXPECT_FALSE(cb.full());
    EXPECT_EQ(cb.capacity(), 3);
    EXPECT_EQ(cb.size(), 1);
    EXPECT_EQ(cb.back(), 1);
    EXPECT_EQ(cb.front(), 1);
}
TEST(Insert, InsertTest4) {
    CircularBuffer cb(3);
    cb.push_back(0);
    cb.push_back(1);
    cb.insert(2, 2);
    EXPECT_FALSE(cb.empty());
    EXPECT_TRUE(cb.full());
    EXPECT_EQ(cb.back(), 2);
    EXPECT_EQ(cb.front(), 0);
    EXPECT_EQ(cb[1], 1);
}