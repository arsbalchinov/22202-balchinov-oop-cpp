#include "FileReader.h"

using namespace std;

FileReader::FileReader(string filename) {
    this->filename = filename;
}

void FileReader::open() {
    file.open(filename);
}

bool FileReader::hasNext() {
    return !file.eof();
}

string FileReader::next() {
    if(!hasNext()) {
        return "";
    }
    string text;
    getline(file, text);
    return text;
}

void FileReader::close() {
    file.close();
}

void FileReader::reset() {
    file.clear();
    file.seekg(0, ios_base::beg);
}