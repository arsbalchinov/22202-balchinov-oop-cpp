#include <gtest/gtest.h>
#include "../CircularBuffer.h"

TEST(PopBack, TestBack1) {
    CircularBuffer cb;
    EXPECT_THROW(cb.pop_back(), out_of_range);
}
TEST(PopBack, TestBack2) {
    CircularBuffer cb(1, 3);
    EXPECT_TRUE(cb.full());
    EXPECT_EQ(cb.pop_back(), 3);
    EXPECT_THROW(cb.pop_back(), out_of_range);
}
TEST(PopBack, TestBack3) {
    CircularBuffer cb(5);
    cb.push_back(2);
    cb.push_back(3);
    EXPECT_EQ(cb.pop_back(), 3);
    EXPECT_EQ(cb.size(), 1);
    EXPECT_EQ(cb.back(), 2);
    EXPECT_EQ(cb.front(), 2);
}
TEST(PopBack, TestBack4) {
    CircularBuffer cb(5, 10);
    EXPECT_FALSE(cb.empty());
    EXPECT_EQ(cb.capacity(), 5);
    cb.push_back(1);
    cb.push_back(3);
    EXPECT_EQ(cb.pop_back(), 3);
    EXPECT_EQ(cb.front(), 10);
    EXPECT_EQ(cb.back(), 1);
}
TEST(PopFront, TestFront1) {
    CircularBuffer cb;
    EXPECT_TRUE(cb.empty());
    EXPECT_THROW(cb.pop_front(), out_of_range);
}
TEST(PopFront, TestFront2) {
    CircularBuffer cb(3);
    EXPECT_TRUE(cb.empty());
    EXPECT_EQ(cb.capacity(), 3);
    cb.push_front(0);
    cb.push_front(1);
    EXPECT_FALSE(cb.empty());
    EXPECT_EQ(cb.size(), 2);
    EXPECT_EQ(cb.pop_front(), 1);
    EXPECT_EQ(cb.pop_front(), 0);
}
TEST(PopFront, TestFront3) {
    CircularBuffer cb(5, 10);
    EXPECT_EQ(cb.capacity(), 5);
    EXPECT_TRUE(cb.full());
    cb.push_front(5);
    EXPECT_EQ(cb.pop_front(), 5);
    EXPECT_EQ(cb.pop_front(), 10);
}