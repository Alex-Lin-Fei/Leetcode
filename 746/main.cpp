#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size() + 1, 0);
    if (cost.size() < 2)
        return 0;
    for (int i = 2; i <= cost.size(); i++)
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    return dp[cost.size()];
}

int main() {
    vector<int> cost;
    cost.push_back(10);
    cost.push_back(15);
    cost.push_back(20);
//    cost.push_back(1);
//    cost.push_back(1);
//    cost.push_back(100);
//    cost.push_back(1);
//    cost.push_back(1);
//    cost.push_back(100);
//    cost.push_back(1);

    std::cout << minCostClimbingStairs(cost)<< std::endl;
    return 0;
}
