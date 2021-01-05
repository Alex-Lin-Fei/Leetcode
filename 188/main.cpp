#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.size() < 2)
        return 0;
    int sum = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] - prices[i - 1] > 0)
            sum += prices[i] - prices[i - 1];
    }
    return sum;
}

int maxProfit(int k, vector<int>& prices) {
//    vector<pair<int, int>> dp(k);
//    if(!k)
//        return 0;
//    if (k > prices.size() / 2)
//        return maxProfit(prices);
//    for (int i = 0; i < k; i++)
//        dp[i].second = INT16_MIN;
//    for (auto& price: prices) {
//        for (int j = 0; j < k; j++) {
//            if (!j)
//                dp[j].second = max(dp[j].second, -price);
//            else {
//                dp[j].second = max(dp[j].second, dp[j - 1].first - price);
//            }
//            dp[j].first = max(dp[j].first, dp[j].second + price);
//        }
//    }
//    return dp[k - 1].first;
    if (k > prices.size() / 2)
        return maxProfit(prices);
    vector<vector<pair<int, int>>> dp(prices.size(), vector<pair<int, int>>(k));
    for (int i = 0; i < prices.size(); i++) {
        for (int j = k; j >= 1; j--) {
            if (i == 0) {
                dp[i][j].first = 0;
                dp[i][j].second = -prices[i];
            }
            else {
                dp[i][j].first = max(dp[i - 1][j].first, dp[i - 1][j].second + prices[i]);
                dp[i][j].second = max(dp[i - 1][j].second, dp[i - 1][j - 1].first - prices[i]);
            }
        }
    }
    return dp[prices.size() - 1][k].first;
}


int main() {
    vector<int>prices;
    prices.push_back(2);
    prices.push_back(6);
    prices.push_back(8);
    prices.push_back(7);
    prices.push_back(8);
    prices.push_back(7);
    prices.push_back(9);
    prices.push_back(4);
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(4);
    prices.push_back(5);
    prices.push_back(8);




    int k = 2;

    std::cout << maxProfit(k, prices) << std::endl;
    return 0;
}
