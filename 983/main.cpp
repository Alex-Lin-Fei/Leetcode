#include <iostream>
#include <vector>
using namespace std;

int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int>dp(days[days.size() - 1] + 1, INT16_MAX);
    dp[0] = 0;
    int idx = 0;
    for (int i = 1; i < dp.size(); i++) {
        if (i != days[idx])
            dp[i] = dp[i - 1];
        else {
            dp[i] = min(dp[i], dp[max(0, i - 1)] + costs[0]);
            dp[i] = min(dp[i], dp[max(0, i - 7)] + costs[1]);
            dp[i] = min(dp[i], dp[max(0, i - 30)] + costs[2]);
            idx++;
        }
    }
    return dp[dp.size() - 1];
}

int main() {

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
