#include <gtest/gtest.h>
#include "../CircularBuffer.h"

TEST(Swap, SwapTest1) {
    int capacity = 3;
    CircularBuffer<int> cb(capacity, 1);
    CircularBuffer<int> cb1 = cb;
    EXPECT_TRUE(cb == cb1);
    cb.swap(cb1);
    EXPECT_TRUE(cb == cb1);
}
TEST(Swap, SwapTest2) {
    CircularBuffer<int> cb(5, 0);
    CircularBuffer<int> cb1(5, 1);
    EXPECT_FALSE(cb == cb1);
    cb.swap(cb1);
    for (int i = 0; i < cb.size(); i++) {
        EXPECT_EQ(cb[i], 1);
        EXPECT_EQ(cb1[i], 0);
    }
}
TEST(Swap, SwapTest3) {
    int capacity = 3;
    int capacity1 = 5;
    CircularBuffer<int> cb(capacity, 1);
    CircularBuffer<int> cb1(capacity1, 1);
    EXPECT_TRUE(cb != cb1);
    cb.swap(cb1);
    EXPECT_EQ(cb.capacity(), capacity1);
    EXPECT_EQ(cb1.capacity(), capacity);
    for (int i = 0; i < capacity; i++) {
        EXPECT_EQ(cb[i], cb1[i]);
    }
    cb.swap(cb1);
    EXPECT_EQ(cb.capacity(), capacity);
    EXPECT_EQ(cb1.capacity(), capacity1);
    for (int i = 0; i < capacity; i++) {
        EXPECT_EQ(cb[i], cb1[i]);
    }
}