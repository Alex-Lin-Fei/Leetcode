#include <iostream>
#include <vector>
using namespace std;

bool stoneGame(vector<int>& piles) {
    vector<vector<pair<int, int>>>dp(piles.size(), vector<pair<int, int>>(piles.size()));
    for (int i = 0; i < dp.size(); i++) {
        dp[i][i].first = piles[i];
        dp[i][i].second = 0;
    }
    for (int l = 1; l < piles.size(); l++) {
        for (int i = 0; i < dp.size() - l; i++) {
            int j = i + l;
            int left = piles[i] + dp[i + 1][j].second;
            int right = piles[j] + dp[i][j - 1].second;
            if (right < left) {
                dp[i][j].first = left;
                dp[i][j].second = dp[i + 1][j].first;
            }
            else {
                dp[i][j].first = right;
                dp[i][j].second = dp[i][j - 1].first;
            }
        }
    }
    return dp[0][piles.size() - 1].first - dp[0][piles.size() - 1].second;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
