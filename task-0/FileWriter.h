#ifndef TASK_0_FILEWRITER_H
#define TASK_0_FILEWRITER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class FileWriter {
private:
    string filename;
    ofstream file;
public:
    explicit FileWriter(string filename);
    void open();
    void write(vector<string> &strings);
    void close();
};

#endif //TASK_0_FILEWRITER_H
