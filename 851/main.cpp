#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<int> * v, vector<int>& quiet, vector<int> & answer, int x) {
    int ans = quiet[x];
    int t = x;

    for (auto & i: v[x]) {
        int a;
        if (answer[i] != -1) {
            a = answer[i];
        } else {
            a = dfs(v, quiet, answer, i);
        }
        if (ans > quiet[a]) {
            ans = quiet[a];
            t = a;
        }
    }

    return t;
}

vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    vector<int> v[quiet.size()];
    for (auto & i : richer)
        v[i[1]].push_back(i[0]);

    vector<int> res(quiet.size(), -1);
    for (int i = 0; i < res.size(); i++) {
        res[i] = dfs(v, quiet, res, i);
    }

    for (auto& i: res)
        cout << i << ' ';
}


int main() {
    vector<vector<int>> richer(7,vector<int>(2));

    return 0;
}
