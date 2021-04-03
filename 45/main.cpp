#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int>& nums) {
    vector<int> dp(nums.size(), INT32_MAX);

    dp[0] = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < min((int) nums.size(), i + nums[i] + 1); j++)
            dp[j] = min(dp[j], dp[i] + 1);

    }

    return dp.back();
}

int main() {
    vector<int> nums {2,3,1,1,4};
    std::cout << jump(nums) << std::endl;
    return 0;
}
