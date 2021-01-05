#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int pre(map<int, int>& temp, int idx) {
    if (temp[idx] > 0 || idx == 1)
        return temp[idx];
    else {
        temp[idx] = (idx % 2 == 1) ? pre(temp, idx * 3 + 1) + 1: pre(temp, idx/2) + 1;
        return temp[idx];
    }
}

bool myCmp(pair<int, int>& a, pair<int, int>& b) {
    return (a.second == b.second)? a.first < b.first: a.second < b.second;
}

int getKth(int lo, int hi, int k) {
    map<int, int> temp;
    vector<pair<int, int>> ans;
    temp[1] = 0;
    for (int i = lo; i <= hi; i++) {
        temp[i] = pre(temp, i);
    }
    for (int i = lo; i <= hi; i++) {
        ans.push_back(make_pair(i, temp[i]));
    }

    sort(ans.begin(), ans.end(), myCmp);
    return ans[k - 1].first;
}

int main() {
    cout << getKth(12, 15, 2);
    return 0;
}
