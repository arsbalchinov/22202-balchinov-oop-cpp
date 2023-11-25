#include "gtest/gtest.h"
#include "../FileWriter.h"
using namespace std;

TEST(FileWriter, String) {
    string testFile = "test.txt";
    FileWriter filewriter(testFile);
    filewriter.open();

    vector<string> data;
    data.emplace_back("hello");
    data.emplace_back("500");
    data.emplace_back("10.25");
    filewriter.write(data);
    filewriter.close();

    ifstream file;
    file.open(testFile);

    string str;
    getline(file, str);
    ASSERT_EQ(str, "hello; 500; 10.25");

    getline(file, str);
    ASSERT_EQ(str, "");
    ASSERT_TRUE(file.eof());

    file.close();
}