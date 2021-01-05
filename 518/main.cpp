#include <iostream>
#include <vector>
using namespace std;

int change(int amount, vector<int>& coins) {
    vector<bool> dp;
    dp.resize(amount + 1);
    dp[0] = true;
    for (int i = 0; i < coins.size(); i++)
        for (int j = 1; j < dp.size(); j++)
            if (j >= coins[i])
                dp[j] = dp[j] + dp[j - coins[i]];
    return dp[amount];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
