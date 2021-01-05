#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> ans;
void permute(vector<int>& nums, vector<int>& res, int index) {
    if (index == nums.size()) {
        ans.push_back(res);
    }
    else {
        for (int i = 0; i < nums.size(); i++) {
            bool ok = true;
            for (int j = 0; j < index; j++) {
                if (res[j] == nums[i])
                    ok = false;
            }
            if (ok) {
                res[index] = nums[i];
                permute(nums, res, index + 1);
            }
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<int> res = vector<int>(nums.size(), 0);
    permute(nums, res, 0);
    return ans;
}

void backtracking(vector<int> & nums, int level, vector<vector<int>> & ans) {
    if (level == nums.size() - 1) {
        ans.push_back(nums);
        return;
    }
    for(int i = level; i < nums.size(); i++) {
        swap(nums[i], nums[level]);
        backtracking(nums, level + 1, ans);
        swap(nums[i], nums[level]);
    }
}

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    permute(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
