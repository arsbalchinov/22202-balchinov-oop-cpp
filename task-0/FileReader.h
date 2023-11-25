#ifndef TASK_0_FILEREADER_H
#define TASK_0_FILEREADER_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class FileReader {
private:
    string filename;
    ifstream file;
public:
    explicit FileReader(string filename);
    void open();
    string next();
    bool hasNext();
    void close();
    void reset();
};

#endif //TASK_0_FILEREADER_H
