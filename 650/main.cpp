#include <iostream>
#include <vector>
using namespace std;
const int INF = 0x9999999;
int minSteps(int n) {
    vector<int>dp(n + 1, INF);
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i % j == 0) {
                dp[i] = min(dp[j] + i / j, dp[i]);
            }
        }
    }

    return dp[n];
}
int minStepsB(int n) {
    int d = 2;
    int ans = 0;
    while (n > 1) {
        while (n % d == 0) {
            ans += d;
            n /= d;
        }
        d++;
    }
    return ans;
}

int main() {
    std::cout << minStepsB(3) << std::endl;
    return 0;
}
