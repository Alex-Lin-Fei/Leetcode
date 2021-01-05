#include <iostream>
#include <vector>
using namespace std;

int waysToChange(int n) {
//    vector<int>coin;
//    coin.push_back(25);
//    coin.push_back(10);
//    coin.push_back(5);
//    coin.push_back(1);
//    vector<int> dp(n + 1);
//    dp[0] = 1;
//    for (int i = 0; i < 4; i++) {
//        for (int j = 1; j < dp.size(); j++) {
//            if (j >= coin[i])
//                dp[j] = dp[j] + dp[j - coin[i]];
//        }
//    }
//    return dp[n]%1000000007;

int ans = 0;
for (int i = 0; i * 25 <= n; i++) {
    int r = n - i * 25;
    int a0 = r / 10;
    int b0 = (r - a0 * 10) / 5;
    ans = (ans + (long long)(a0 + 1) * (a0 + b0 + 1) % 1000000007) % 1000000007;
}
    return ans;
}

int main() {
    std::cout << waysToChange(5) << std::endl;
    return 0;
}
