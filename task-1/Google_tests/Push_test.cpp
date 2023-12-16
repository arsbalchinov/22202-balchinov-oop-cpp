#include <gtest/gtest.h>
#include "../CircularBuffer.h"

TEST(PushBack, TestBack1) {
    CircularBuffer cb;
    EXPECT_TRUE(cb.empty());
    EXPECT_THROW(cb.push_back(3), out_of_range);
}
TEST(PushBack, TestBack2) {
    CircularBuffer cb(3);
    EXPECT_TRUE(cb.empty());
    EXPECT_EQ(cb.capacity(), 3);
    cb.push_back(0);
    cb.push_back(1);
    EXPECT_FALSE(cb.empty());
    EXPECT_EQ(cb.size(), 2);
    EXPECT_EQ(cb.front(), 0);
    EXPECT_EQ(cb.back(), 1);
}
TEST(PushBack, TestBack3) {
    CircularBuffer cb(10);
    EXPECT_TRUE(cb.empty());
    cb.push_back(3);
    EXPECT_EQ(cb.size(), 1);
    cb.push_back(5);
    EXPECT_EQ(cb.size(), 2);
    for (int i = 0; i < 8; i++) {
        cb.push_back((char)i);
        EXPECT_EQ(cb.size(), i+3);
        EXPECT_EQ(cb[i+2], i);
    }
    EXPECT_TRUE(cb.full());
    cb.push_back(1);
    EXPECT_TRUE(cb.full());
    EXPECT_EQ(cb.size(), 10);
    EXPECT_EQ(cb.front(), 5);
}
TEST(PushFront, TestFront1) {
    CircularBuffer cb;
    EXPECT_TRUE(cb.empty());
    EXPECT_THROW(cb.push_front(3), out_of_range);
}
TEST(PushFront, TestFront2) {
    CircularBuffer cb(3);
    EXPECT_TRUE(cb.empty());
    EXPECT_EQ(cb.capacity(), 3);
    cb.push_front(0);
    cb.push_front(1);
    EXPECT_FALSE(cb.empty());
    EXPECT_EQ(cb.size(), 2);
    EXPECT_EQ(cb.front(), 1);
    EXPECT_EQ(cb.back(), 0);
}
TEST(PushFront, TestFront3) {
    CircularBuffer cb(10);
    EXPECT_EQ(cb.capacity(), 10);
    EXPECT_TRUE(cb.empty());
    cb.push_front(3);
    EXPECT_EQ(cb.size(), 1);
    cb.push_front(5);
    EXPECT_EQ(cb.size(), 2);
    for (int i = 0; i < 8; i++) {
        cb.push_front((char)i);
        EXPECT_EQ(cb.size(), i+3);
        EXPECT_EQ(cb[0], i);
    }
    EXPECT_TRUE(cb.full());
    cb.push_front(1);
    EXPECT_TRUE(cb.full());
    EXPECT_EQ(cb.front(), 1);
}