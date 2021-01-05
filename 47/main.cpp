#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<int>>ans;
map<int, int> sum;
void dfs(vector<int> & nums, vector<int>& temp, int cur) {
    if (cur == nums.size())
        ans.push_back(temp);
    else {
        for (int i = 0; i < nums.size(); i++) {
            if (!i || nums[i] != nums[i - 1]) {
                int sum1 = 0;
                int x = nums[i];
                for (int j = 0; j < cur; j++) {
                    if (temp[j] == x)
                        sum1++;
                }
                if (sum1 == sum[x])
                    continue;
                temp.push_back(nums[i]);
                dfs(nums, temp, cur + 1);
                temp.pop_back();
            }
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    ans.clear();
    sort(nums.begin(), nums.end());
    vector<int>temp;
    sum.clear();
    for (auto& i: nums) {
        if (sum.count(i))
            sum[i]++;
        else
            sum[i] = 1;
    }
    dfs(nums, temp, 0);
    for (auto& row: ans) {
        for (auto &i: row)
            cout << i << ' ';
        cout << endl;
    }
    return ans;
}

int main() {
    vector<int>nums = {1,1,2};
    permuteUnique(nums);
    return 0;
}
