#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> largeGroupPositions(string s) {
    vector<vector<int>> ans;
    int start = 0;

    while (start < s.size()) {
        vector<int> tmp(2);
        tmp[0] = start;
        while (s[start + 1] == s[start])
            start++;
        tmp[1] = start;
        if (tmp[1] - tmp[0] >= 2)
            ans.push_back(tmp);
        start++;
    }

    return ans;
}

int main() {
    int x=;
    largeGroupPositions("abbxxxxxzzy");

    return 0;
}
