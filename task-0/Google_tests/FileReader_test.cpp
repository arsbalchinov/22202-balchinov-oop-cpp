#include "gtest/gtest.h"
#include "../FileReader.h"
using namespace std;

TEST(FileReader, EmptyFile) {
    ofstream testFile("empty.txt");
    testFile.close();

    FileReader filereader("empty.txt");
    filereader.open();

    ASSERT_EQ(filereader.next(), "");
    ASSERT_FALSE(filereader.hasNext());
}

TEST(FileReader, String) {
    ofstream testFile("file.txt");
    testFile << ("Hello World");
    testFile.close();

    FileReader filereader("file.txt");
    filereader.open();

    ASSERT_TRUE(filereader.hasNext());
    ASSERT_EQ(filereader.next(), "Hello World");
}

TEST(FileReader, ManyStrings) {
    ofstream testFile("file.txt");
    testFile << ("Hello World\nAbc Bca\nFileRead");
    testFile.close();

    FileReader filereader("file.txt");
    filereader.open();

    ASSERT_TRUE(filereader.hasNext());
    ASSERT_EQ(filereader.next(), "Hello World");
    ASSERT_TRUE(filereader.hasNext());
    ASSERT_EQ(filereader.next(), "Abc Bca");
    ASSERT_TRUE(filereader.hasNext());
    ASSERT_EQ(filereader.next(), "FileRead");
    ASSERT_FALSE(filereader.hasNext());
}