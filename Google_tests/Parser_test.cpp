#include "gtest/gtest.h"
#include "../Parser.h"
using namespace std;

TEST(Parser, EmptyString) {
    Parser parser;
    string str;
    vector<string> result = parser.parse(str);

    ASSERT_EQ(result.size(), 0);
}

TEST(Parser, StringWithoutWords) {
    Parser parser;
    string str = "\t \t \t \t \n";
    vector<string> result = parser.parse(str);

    ASSERT_EQ(result.size(), 0);
}

TEST(Parser, String) {
    Parser parser;
    string str = "abc bca 123";
    vector<string> result = parser.parse(str);

    ASSERT_EQ(result.size(), 3);
    ASSERT_EQ(result[0], "abc");
    ASSERT_EQ(result[1], "bca");
    ASSERT_EQ(result[2], "123");
}

TEST(Parser, UpperString) {
    Parser parser;
    string str = "ABCDE BCA CAD 1234";
    vector<string> result = parser.parse(str);

    ASSERT_EQ(result.size(), 4);
    ASSERT_EQ(result[0], "abcde");
    ASSERT_EQ(result[1], "bca");
    ASSERT_EQ(result[2], "cad");
    ASSERT_EQ(result[3], "1234");
}