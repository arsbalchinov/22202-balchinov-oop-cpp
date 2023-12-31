#include <gtest/gtest.h>
#include "../CircularBuffer.h"

TEST(Constructor, emptyTest) {
    CircularBuffer cb;
    EXPECT_TRUE(cb.empty());
    EXPECT_TRUE(cb.full());
    EXPECT_EQ(cb.capacity(), 0);
}
TEST(Constructor, capacityTest1) {
    CircularBuffer cb(0);
    EXPECT_TRUE(cb.empty());
    EXPECT_TRUE(cb.full());
    EXPECT_EQ(cb.capacity(), 0);
}
TEST(Constructor, capacityTest2) {
    CircularBuffer cb(10);
    EXPECT_TRUE(cb.empty());
    EXPECT_FALSE(cb.full());
    EXPECT_EQ(cb.capacity(), 10);
}
TEST(Constructor, constructorTest) {
    CircularBuffer cb(10, 5);
    EXPECT_FALSE(cb.empty());
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(cb[i], 5);
    }
    EXPECT_TRUE(cb.full());
}
TEST(Constructor, copyTest) {
    CircularBuffer cb(10, 3);
    EXPECT_FALSE(cb.empty());
    EXPECT_TRUE(cb.full());
    EXPECT_EQ(cb.capacity(), 10);
    CircularBuffer cb1(cb);
    EXPECT_TRUE(cb == cb1);
    cb.push_front(0);
    EXPECT_TRUE(cb != cb1);
    cb1.push_front(0);
    EXPECT_TRUE(cb == cb1);
}