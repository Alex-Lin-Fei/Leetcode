#include <iostream>
#include <vector>
using namespace std;

int integerBreak(int n) {
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 4;
    dp[5] = 6;
    dp[6] = 9;
    for (int i = 7; i <= n; i++)
        dp[i] = 3 * dp[i - 3];
    return dp[n];
}

int main() {
    std::cout << integerBreak(58) << std::endl;
    return 0;
}
