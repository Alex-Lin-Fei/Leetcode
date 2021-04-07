#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

vector<string> maxNumOfSubstrings(string s) {
    vector <string> ans;

//    找出所有字母的初始区间

    vector <pair<int, int>> records(26, {-1, -1});

    for (int i = 0; i < s.length(); i++) {
        if (records[s[i] - 'a'].first == -1)
            records[s[i] - 'a'] = {i, i};
        else
            records[s[i] - 'a'].second = i;
    }


//    合并区间

    for (int i = 0; i < records.size(); i++) {
        if (records[i].first != -1) {
            for (int j = records[i].first; j <= records[i].second; j++) {
                int idx = s[j] - 'a';
                if (records[i].first <= records[idx].first && records[i].second >= records[idx].second)
                    continue;
                records[i] = {min(records[idx].first, records[i].first), max(records[idx].second, records[i].second)};
                j = records[i].first;
            }
        }
    }

//    排序

    sort(records.begin(), records.end(), [](pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second || (a.second == b.second && a.first > b.first);
    });

//    贪心选取

    int end = -1;

    for (auto &record: records) {
        if (record.first == -1)
            continue;
        if (end == -1 || record.first > end) {
            end = record.second;
            ans.emplace_back(s.substr(record.first, record.second - record.first + 1));
        }
    }

    return ans;
}


int main() {


    return 0;
}
