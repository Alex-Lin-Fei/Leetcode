#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    if (nums.empty())
        return 0;
    vector<int> dp(nums.size(), 1);
    vector<int> count(nums.size(), 1);


    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }
                else if (dp[j] + 1 == dp[i]) {
                    count[i] += count[j];
                }
            }
        }
    }
    int maxL = 0;
    int sum = 0;
    for (auto& i: dp)
        maxL = max(maxL, i);

    for (int i = 0; i < nums.size(); i++) {
        if (dp[i] == maxL)
            sum += count[i];
    }
    return sum;
}


int main() {
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);

cout << findNumberOfLIS(nums);
    return 0;
}
