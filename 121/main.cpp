#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minCur = prices[0];
    int maxIn = 0;
    for (auto i = 0; i < prices.size(); i++) {
        maxIn = max(maxIn, prices[i] - minCur);
        minCur = min(minCur, prices[i]);
    }
    return maxIn;
}

int main() {
    vector<int> pr;
    pr.push_back(7);
    pr.push_back(1);
    pr.push_back(5);
    pr.push_back(3);
    pr.push_back(6);
    pr.push_back(4);

    std::cout << maxProfit(pr) << std::endl;
    return 0;
}
