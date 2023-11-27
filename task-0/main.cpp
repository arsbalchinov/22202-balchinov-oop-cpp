#include <iostream>
#include <vector>
#include <string>
#include "FileReader.h"
#include "Parser.h"
#include "Stats.h"
#include "FileWriter.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        exit(1);
    }
    string filename = argv[1];
    FileReader readFile(filename);
    readFile.open();
    Stats stat;
    Parser parser;

    while (readFile.hasNext()) {
        string line = readFile.next();
        vector<string> words = parser.parse(line);
        for (string &word : words) {
            stat.addWord(word);
        }
    }
    readFile.close();
    filename = argv[2];
    FileWriter writer(filename);
    writer.open();

    vector<pair<string, int>> sorted = stat.getSortedList();
    int wordCount = stat.getWordCount();
    for (pair<string, int> &wordPair : sorted) {
        vector<string> data;
        data.push_back(wordPair.first);
        data.push_back(to_string(wordPair.second));
        data.push_back(to_string((double) wordPair.second / wordCount * 100));
        writer.write(data);
    }

    writer.close();
}