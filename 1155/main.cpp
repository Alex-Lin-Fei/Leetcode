#include <iostream>
#include <vector>
using namespace std;

int numRollsToTarget(int d, int f, int target) {
    if (target < d || target > d * f)
        return 0;
    if (d == 1 || target == d || target == d * f)
        return 1;
    vector<vector<int>>dp(1+d, vector<int>(target+1, 0));
    auto mod = 1e9 + 7;

    int minf = min(f, target);
    for (int i = 1; i <= minf; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= d; i++) {
        for (int j = i; j <= min(target, f * i); j++) {
            for (int k = 1; k <= f && j - k >= 0; k++)
                dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % mod;
        }
    }
    return dp[d][target];
}

int main() {
    std::cout << numRollsToTarget(30, 30, 500) << std::endl;
    return 0;
}
