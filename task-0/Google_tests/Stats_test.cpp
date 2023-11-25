#include "gtest/gtest.h"
#include "../Stats.h"
using namespace std;

TEST(Stats, EmptyList) {
    Stats emptyList;
    vector<pair<string, int>> emptySortedList = emptyList.getSortedList();

    ASSERT_EQ(emptySortedList.size(), 0);
}

TEST(Stats, Words) {
    Stats statList;
    string str = "abc";
    statList.addWord(str);
    statList.addWord(str);
    str = "bca";
    statList.addWord(str);
    statList.addWord(str);
    statList.addWord(str);
    str = "123";
    statList.addWord(str);
    ASSERT_EQ(statList.getWordCount(), 6);

    vector<pair<string, int>> SortedList = statList.getSortedList();
    ASSERT_EQ(SortedList[0].first, "bca");
    ASSERT_EQ(SortedList[0].second, 3);
    ASSERT_EQ(SortedList[1].first, "abc");
    ASSERT_EQ(SortedList[1].second, 2);
    ASSERT_EQ(SortedList[2].first, "123");
    ASSERT_EQ(SortedList[2].second, 1);
}