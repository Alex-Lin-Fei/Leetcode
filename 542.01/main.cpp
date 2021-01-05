#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int r = matrix.size();
    int c = matrix[0].size();
    vector<vector<int>> dp(r, vector<int>(c, INT16_MAX));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (!matrix[i][j])
                dp[i][j] = 0;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (matrix[i][j])
            {
                if (i>0)
                    dp[i][j] = min(dp[i][j], dp[i-1][j]);
                if (j > 0)
                    dp[i][j] = min(dp[i][j], dp[i][j-1]);
            }

    for (int i = r-1; i >= 0; i--)
        for (int j = c; j >=0; j--)
            if (matrix[i][j]) {
                if (i < r - 1)
                    dp[i][j] = min(dp[i][j], dp[i + 1][j]);
                if (j < c - 1)
                    dp[i][j] = min(dp[i][j], dp[i][j + 1]);
            }
    return dp;
}

int main() {

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
