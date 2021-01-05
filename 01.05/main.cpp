#include <iostream>
#include <vector>
using namespace std;

bool oneEditAway(string first, string second) {
    vector<vector<int>> dp(first.size() + 1, vector<int>(second.size() + 1));
    for (int i = 0; i < dp.size(); i++)
        dp[i][0] = i;
    for (int i = 0; i < dp[0].size(); i++)
        dp[0][i] = i;
    for (int i = 1; i < dp.size(); i++) {
        for (int j = 1; j < dp[0].size(); j++) {
            int diff = (first[i - 1] == second[j - 1]) ? 0 : 1;
            dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]) + 1, dp[i - 1][j - 1] + diff);
        }
    }
    return dp[first.size()][second.size()] < 2;
}

int main() {
    std::cout << oneEditAway("ab", "bc") << std::endl;
    return 0;
}
