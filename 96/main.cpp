#include <iostream>
using namespace std;

int numTrees(int n) {
    int dp[n + 1];
    for (auto& i: dp)
        i = 0;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    return dp[n];
}

int main() {
    numTrees(3);
    return 0;
}
