#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool myCmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), myCmp);
    vector<int>dp(pairs.size(), 1);
    int maxL = 1;
    int end = pairs[0][1];
    for (int i = 1; i < pairs.size(); i++)
        if (pairs[i][0] > end) {
            end = pairs[i][1];
            maxL++;
        }

    return maxL;
}

int main() {
    vector<vector<int>>v;
    int l = 7;
    for (int i = 0; i < l; i++) {
        vector<int>k(2);
        v.push_back(k);
        for (int j = 0; j < 2; j++) {
            int n;
            cin >> n;
            v[i].push_back(n);
        }
    }
    for (int i = 0; i < l; i++) {
        cout << v[i][0] << ' ' << v[i][1] << endl;
    }
    std::cout << findLongestChain(v) << std::endl;

    return 0;
}
