#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int dp_0 = 0, dp_1 = INT16_MIN;
    for (int i = 0; i < prices.size(); i++) {
        int temp = dp_0;
        dp_0 = max(dp_0, dp_1 + prices[i]);
        dp_1 = max(dp_1, temp - prices[i]);
    }
    return dp_0;
}

int main() {
    vector<int>pr;
    pr.push_back(7);
    pr.push_back(1);
    pr.push_back(5);
    pr.push_back(3);
    pr.push_back(6);

    pr.push_back(4);

    std::cout << maxProfit(pr) << std::endl;
    return 0;
}
