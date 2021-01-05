#include <iostream>
#include <vector>
using namespace std;

int getMoneyAmount(int n) {
    vector<vector<int>>dp(n + 1, vector<int>(n + 1));

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int minI = INT16_MAX;
            for (int k = i; k < i + l - 1; k++) {
                minI = min(minI, k + max(dp[i][k - 1], dp[k + 1][i + l - 1]));
            }
            dp[i][i + l - 1] = minI;
        }
    }

    return dp[1][n];
}

int main() {
    std::cout << getMoneyAmount(10) << std::endl;
    return 0;
}
