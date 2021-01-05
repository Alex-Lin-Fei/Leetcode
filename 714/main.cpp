#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    if (prices.size() < 2)
        return 0;
    int dp_i_0 = 0;
    int dp_i_1 = -prices[0];
    for (int i = 1; i < prices.size(); i++) {
        int temp = dp_i_0;
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i] - fee);
        dp_i_1 = max(dp_i_1, temp - prices[i]);
    }
    return dp_i_0;
}

int main() {
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(3);
    prices.push_back(7);
    prices.push_back(5);
    prices.push_back(10);
    prices.push_back(3);

    int fee = 3;
    std::cout << maxProfit(prices, fee) << std::endl;
    return 0;
}
