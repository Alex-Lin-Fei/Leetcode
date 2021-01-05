#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool myCompare(pair<int, int>& a, pair<int, int>& b) {
    return (a.first != b.first) ? a.first < b.first: a.second > b.second;
}

int bestSeqAtIndex(vector<int> &height, vector<int> &weight) {
    vector<pair<int, int>> person;
    person.resize(height.size());
    vector<int> ans;
    ans.resize(person.size());
    for (int i = 0; i < person.size(); i++) {
        person[i] = make_pair(height[i], weight[i]);
    }
    sort(person.begin(), person.end(), myCompare);
//    for (int i = 0; i < person.size(); i++) {
//        int index = lower_bound(ans.begin(), ans.end(), person[i].second) - ans.begin();
//        if (index == ans.size())
//            ans.push_back(person[i].second);
//        else
//            ans[i] = person[i].second;
//    }
//    return ans.size();
    int piles = 0;
    for (int i = 0; i < person.size(); i++) {
        int poker = person[i].second;
        int left = 0, right = piles;
        while (left < right) {
            int mid = (left + right) / 2;
            if (ans[mid] > poker)
                right = mid;
            else if (ans[mid] < poker)
                left = mid + 1;
            else {
                right = mid;
            }
        }
        if (left == piles)
            piles++;
        ans[left] = poker;
    }
    return piles;
}


int main() {

    return 0;
}
