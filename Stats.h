#ifndef TASK_0_STATS_H
#define TASK_0_STATS_H
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;

class Stats {
private:
    unordered_map<string, int>  statistics;
    int wordCount;
public:
    Stats();
    void addWord(string &word);
    int getWordCount() const;
    vector<pair<string, int>> getSortedList();
};

#endif //TASK_0_STATS_H
