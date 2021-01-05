#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));
    dp[0][0] = grid[0][0];
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++) {
            if (!i || !j) {
                if (!i && !j)
                    continue;
                else if (!i) {
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                }
            }
            else
                dp[i][j] = min(dp[i-1][j], dp[i][j - 1]) + grid[i][j];
        }
    return dp[grid.size() - 1][grid[0].size() - 1];
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
