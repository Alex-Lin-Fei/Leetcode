#include <iostream>
#include <vector>
using namespace std;

//int maxSubArray(vector<int>& nums) {
//    int tot = nums[nums.size() - 1];
//    int start = tot;
//    for (int i = nums.size() - 2; i >= 0; i--) {
//        if (start < 0)
//            start = 0;
//        start += nums[i];
//        if (start > tot)
//            tot = start;
//    }
//    return tot;
//}

int maxSubArray(vector<int>& nums) {
    vector<int>dp(nums.size());
    dp[0] = nums[0];
    int maxI = dp[0];
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(nums[i], nums[i] + dp[i - 1]);
        maxI = max(maxI, dp[i]);
    }
    return maxI;
}

int main() {
    vector<int>nums;
    nums.push_back(-2);
//    nums.push_back(1);
//    nums.push_back(-3);
//    nums.push_back(4);
    nums.push_back(-1);
//    nums.push_back(2);
//    nums.push_back(1);
//    nums.push_back(-5);
//    nums.push_back(4);

    std::cout << maxSubArray(nums)<< std::endl;
    return 0;
}
