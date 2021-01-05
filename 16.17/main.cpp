#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int i;
    int ans = nums[0];
    for (i = 1; i < nums.size(); i++) {
        if (nums[i] > 0)
            break;
        ans = max(nums[i], ans);
    }
    if (i == nums.size())
        return ans;
    vector<int>dp(nums.size());
    dp[0] = max(0, nums[0]);
    ans = max(0, dp[0]);
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {
    vector<int>nums;
//    nums.push_back(-2);
    nums.push_back(-1);
    std::cout << maxSubArray(nums) << std::endl;
    return 0;
}
