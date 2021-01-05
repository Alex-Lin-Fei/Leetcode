#include <iostream>
#include <vector>
using namespace std;


int ans;
void dfs(vector<int>& v, int i, int s, int target) {
    if (i == v.size() && s == target)
        ans++;
    dfs(v, i+1, s+v[i], target);
    dfs(v, i + 1, s-v[i], target);
}

int findTargetSumWays(vector<int>& nums, int S) {
//    dfs(nums, 0, 0, S);
//
//    return ans;
    vector<vector<int>> dp(nums.size(), vector<int>(2001));
    dp[0][nums[0] + 1000] = 1;
    dp[0][-nums[0] + 1000] = 1;

    for (int i = 1; i < nums.size(); i++)
        for (int j = -1000; j <= 1000; j++)
            if (dp[i - 1][j + 1000] > 0) {
                dp[i][j + nums[i] + 1000] += dp[i - 1][j + 1000];
                dp[i][j - nums[i] + 1000] += dp[i - 1][j + 1000];
            }
    return S > 1000 ? 0 : dp[nums.size() - 1][S + 1000];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
