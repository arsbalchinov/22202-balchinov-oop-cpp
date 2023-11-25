#include "Stats.h"

using namespace std;

Stats::Stats() {
    wordCount = 0;
}

void Stats::addWord(string &word) {
    statistics[word]++;
    wordCount++;
}

int Stats::getWordCount() const {
    return wordCount;
}

bool cmp(pair<string, int> &a, pair<string, int> &b) {
    return a.second > b.second;
}

vector<pair<string, int>> Stats::getSortedList() {
    vector<pair<string, int>> sortedList = {};
    sortedList.resize(statistics.size());

    copy(statistics.begin(), statistics.end(), sortedList.begin());
    sort(sortedList.begin(), sortedList.end(), cmp);

    return sortedList;
}