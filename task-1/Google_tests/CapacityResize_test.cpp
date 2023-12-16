#include <gtest/gtest.h>
#include "../CircularBuffer.h"

TEST(Capacity, SetCapacityTest1) {
    CircularBuffer cb;
    cb.set_capacity(5);
    EXPECT_EQ(cb.capacity(), 5);
    EXPECT_EQ(cb.size(), 0);
}
TEST(Capacity, SetCapacityTest2) {
    CircularBuffer cb(3, 1);
    cb.set_capacity(0);
    EXPECT_EQ(cb.capacity(), 0);
    EXPECT_EQ(cb.size(), 0);
}
TEST(Capacity, SetCapacityTest3) {
    CircularBuffer cb(5, 1);
    cb.set_capacity(10);
    EXPECT_EQ(cb.capacity(), 10);
    EXPECT_EQ(cb.size(), 5);
    for (int i = 0; i < cb.size(); i++) {
        EXPECT_EQ(cb[i], 1);
    }
}
TEST(Capacity, SetCapacityTest4) {
    CircularBuffer cb(5, 1);
    cb.set_capacity(3);
    EXPECT_EQ(cb.capacity(), 3);
    EXPECT_EQ(cb.size(), 3);
    for (int i = 0; i < cb.size(); i++) {
        EXPECT_EQ(cb[i], 1);
    }
}
TEST(Resize, ResizeTest1) {
    CircularBuffer cb(3, 1);
    int size = cb.size();
    cb.resize(5, 5);
    EXPECT_EQ(cb.capacity(), 5);
    EXPECT_EQ(cb.size(), 5);
    for (int i = 0; i < size; i++) {
        EXPECT_EQ(cb[i], 1);
    }
    for (int i = size; i < cb.size(); i++) {
        EXPECT_EQ(cb[i], 5);
    }
}
TEST(Resize, ResizeTest2) {
    CircularBuffer cb(5, 1);
    cb.resize(3, 5);
    EXPECT_EQ(cb.capacity(), 5);
    EXPECT_EQ(cb.size(), 3);
    for (int i = 0; i < cb.size(); i++) {
        EXPECT_EQ(cb[i], 1);
    }
}