#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int ans=0;
    map<vector<int>, int> dominoM;
    for (auto& domino: dominoes) {
        sort(domino.begin(), domino.end());
        dominoM[domino]++;
    }

    for (auto& item: dominoM)
        ans += item.second * (item.second - 1) / 2;

    return ans;
}

int main() {
    vector<vector<int>> dominoes {{1,2},{2,1},{1,1},{1,2}, {2,2}};

    std::cout << numEquivDominoPairs(dominoes) << std::endl;
    return 0;
}
