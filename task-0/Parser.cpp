#include "Parser.h"

using namespace std;

vector<string> Parser::parse(string &line) {
    vector<string> words;
    int word_len = 0;
    string word;
    for (char& c : line) {
        if (isalnum(c)) {
            word += tolower(c);
            word_len++;
        }

        else if (word_len != 0) {
            words.push_back(word);
            word_len = 0;
            word.clear();
        }
    }

    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}