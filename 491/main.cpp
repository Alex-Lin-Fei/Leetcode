#include <iostream>
#include <vector>
#include <set>
using namespace std;


set<vector<int>> ans;
vector<vector<int>> res;

void dfs(vector<int>& nums, vector<int>& temp, int idx) {
    if (idx == nums.size()) {
        if (temp.size() > 1)
            ans.insert(temp);
        return;
    }

    if (temp.empty() || nums[idx] >= temp.back()) {
        temp.push_back(nums[idx]);
        dfs(nums, temp, idx + 1);
        temp.pop_back();
    }
    dfs(nums, temp, idx + 1);
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    res.clear();
    ans.clear();
    vector<int> temp;
    dfs(nums, temp, 0);
    for (auto &s: ans)
        res.push_back(s);
    return res;
}

int main() {
    vector<int>v;
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);


    findSubsequences(v);
//    cout << res.size();
    for (int i=0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
