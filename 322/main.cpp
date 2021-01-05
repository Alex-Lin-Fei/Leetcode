#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//int coinChange(vector<int>& coins, int amount) {
//    vector<int>dp(amount+1, INT16_MAX);
//    dp[0] = 0;
//    for (auto& i: coins) {
//        for (int j = i; j <= amount; j++) {
//            dp[j] = min(dp[j - i] + 1, dp[j]);
//        }
//    }
//    for (auto& i: dp)
//        cout << i << ' ';
//    cout << endl;
//    return (dp[amount] == INT16_MAX)? -1: dp[amount];
//}

void coinChange(vector<int>& coins, int amount, int index, int nowAns, int& ans) {
    if (!amount) {
        ans = min(ans, nowAns);
        return;
    }
    if (index == coins.size())
        return;
    for (int i = amount / coins[index]; i >= 0 && i + nowAns < ans; i--)
        coinChange(coins, amount - i * coins[index], index + 1, nowAns + i, ans);
}

bool myCmp(int & a, int & b) { return a > b; }

int coinChange(vector<int>& coins, int amount) {
    if (!amount)
        return 0;
    sort(coins.begin(), coins.end(), myCmp);
    int ans = INT16_MAX;
    coinChange(coins, amount, 0, 0, ans);
    return (ans == INT16_MAX)? -1: ans;
}

int main() {
    vector<int>coins;
    coins.push_back(186);
    coins.push_back(419);
    coins.push_back(83);
    coins.push_back(408);
    int a = 6249;
    std::cout << coinChange(coins, a) << std::endl;
    return 0;
}
