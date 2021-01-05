#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int num: nums)
        sum += num;
    if (sum % 2)
        return false;
    sum /= 2;
//    vector<vector<bool>> dp(nums.size() + 1, vector<bool>(sum + 1, false));
//    for (int i = 0; i < dp.size(); i++)
//        dp[i][0] = true;
//    for (int i = 1; i < dp.size(); i++)
//        for (int j = 1; j <= sum; j++)
//            if (j < nums[i - 1])
//                dp[i][j] = dp[i - 1][j];
//            else
//                dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]];
//
//
//    return dp[dp.size() - 1][sum];
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for (int i = 0; i < nums.size(); i++)
        for (int j = sum; j >= 0; j--)
            if (j >= nums[i])
                dp[j] = dp[j] || dp[j - nums[i]];
    return dp[sum];
}

*/
bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (auto &i: nums)
        sum += i;
    if (sum % 2)
        return false;
    sum /= 2;
    vector<int> dp(sum + 1);
    dp[0] = true;
    for (int i = 0; i < nums.size(); i++)
        for (int j = sum; j >= 0; j--)
            if (j >= nums[j])
                dp[j] = dp[j] | dp[j - nums[i]];
            return dp[sum];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
