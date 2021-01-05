#include <iostream>
#include <vector>
using namespace std;

int numTilings(int N) {
    vector<int> dp(max(N, 3) + 1, 0);
    int mod = 1e9 + 7;
    dp [0] = dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;
    for (int i = 4; i <= N; i++) {
        dp[i] = (2*(dp[i-1] % mod) % mod + (dp[i-3] % mod) %mod);
        dp[i] %= mod;
    }

    return dp[N];
}

int main() {
    std::cout << numTilings(30) << std::endl;
    return 0;
}
