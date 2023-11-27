#include "FileWriter.h"

using namespace std;

FileWriter::FileWriter(string filename) {
    this->filename = filename;
}

void FileWriter::open() {
    file.open(filename);
}

void FileWriter::write(vector<string> &strings) {
    for (int i = 0; i < strings.size() - 1; i++) {
        file << strings[i] << "; ";
    }
    file << strings[strings.size() - 1] << '\n';
}

void FileWriter::close() {
    file.close();
}