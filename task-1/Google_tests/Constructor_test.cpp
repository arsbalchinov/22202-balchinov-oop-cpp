#include <gtest/gtest.h>
#include "../CircularBuffer.h"

TEST(Constructor, emptyTest) {
    CircularBuffer<int> cb;
    EXPECT_TRUE(cb.empty());
    EXPECT_TRUE(cb.full());
    EXPECT_EQ(cb.capacity(), 0);
}
TEST(Constructor, capacityTest1) {
    CircularBuffer<int> cb(0);
    EXPECT_TRUE(cb.empty());
    EXPECT_TRUE(cb.full());
    EXPECT_EQ(cb.capacity(), 0);
}
TEST(Constructor, capacityTest2) {
    CircularBuffer<int> cb(10);
    EXPECT_TRUE(cb.empty());
    EXPECT_FALSE(cb.full());
    EXPECT_EQ(cb.capacity(), 10);
}
TEST(Constructor, constructorTest) {
    CircularBuffer<int> cb(10, 5);
    EXPECT_FALSE(cb.empty());
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(cb[i], 5);
    }
    EXPECT_TRUE(cb.full());
}
TEST(Constructor, copyTest) {
    CircularBuffer<int> cb(10, 3);
    EXPECT_FALSE(cb.empty());
    EXPECT_TRUE(cb.full());
    EXPECT_EQ(cb.capacity(), 10);
    CircularBuffer<int> cb1(cb);
    EXPECT_TRUE(cb == cb1);
    cb.push_front(0);
    EXPECT_TRUE(cb != cb1);
    cb1.push_front(0);
    EXPECT_TRUE(cb == cb1);
}