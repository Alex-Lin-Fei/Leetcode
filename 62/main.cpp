#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<long>> vec(m, vector<long>(n));
    vec[m - 1][n - 1] = 1;
    for (int i = 0; i < n - 1; i++)
        vec[m - 1][i] = 1;
    for (int j = 0; j < m - 1; j++)
        vec[j][n - 1] = 1;
    for (int i = m - 2; i >= 0; i--)
        for (int j = n - 2; j >= 0; j--)
            vec[i][j] = vec[i + 1][j] + vec[i][j + 1];
    return vec[0][0];

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    dp[0][1] = 1;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    return dp[m][n];

}

int main() {
    std::cout << uniquePaths(7, 3) << std::endl;
    return 0;
}
