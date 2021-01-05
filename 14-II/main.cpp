#include <iostream>
#include <vector>
using namespace std;

int mod = 1000000007;

long long maxL(long long a, long long b) {
    return (a > b)? a: b;
}

int cuttingRope(int n) {
    if (n == 2)
        return 1;
    vector<long long>dp(n + 1);
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            long long temp = maxL(dp[j], j) * maxL(dp[i - j], i - j);
            dp[i] = maxL(dp[i], temp);
        }
    }
    dp[n] %= mod;
    return dp[n];
}

int main() {
    std::cout << cuttingRope(120) << std::endl;
    return 0;
}
