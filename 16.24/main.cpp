#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> pairSums(vector<int>& nums, int target) {
    vector<vector<int>> ans;

    if (nums.empty())
        return ans;
    sort(nums.begin(), nums.end());


////    二分法
//    for (int i = 0; i < nums.size() - 1; i++) {
//        if (nums[i] >= target)
//            break;
//        auto iter = find(nums.begin() + i + 1, nums.end(), target - nums[i]);
//        if (iter != nums.end()) {
//            ans.push_back({nums[i], *iter});
//            nums.erase(iter);
//        }
//    }

    int l = 0, r = nums.size() - 1;
    while (l < r) {
        if (nums[l] + nums[r] > target)
            r--;
        else if (nums[l] + nums[r] < target)
            l++;
        else
            ans.push_back({nums[l++], nums[r--]});
    }

    return ans;
}

int main() {
    vector<int> nums{};
    auto ans = pairSums(nums, 0);
    for (auto &i: ans)
        cout << i[0] << ' ' << i[1] << endl;

    return 0;
}
