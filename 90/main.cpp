#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void dfs(vector<int> & nums, int cur, vector<int> & subset, vector<vector<int>> & subsets, bool choosePre) {
    if (cur == nums.size()) {
        subsets.push_back(subset);
    } else {
        dfs(nums, cur+1, subset, subsets, false);
        if (!choosePre && cur > 0 && nums[cur] == nums[cur - 1])
            return;
        subset.push_back(nums[cur]);
        dfs(nums, cur + 1, subset, subsets, true);
        subset.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> subsets;
vector<int> subset;

    sort(nums.begin(), nums.end());
    dfs(nums, 0, subset, subsets, true);

    for (auto& s: subsets) {
        cout << "* ";
        for (auto& i: s)
            cout << i << ' ';
        cout << '*'<< endl;
    }

    return subsets;
}

int main() {
    vector<int> nums{1, 2,2};
    subsetsWithDup(nums);

    return 0;
}
