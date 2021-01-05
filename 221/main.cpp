#include <iostream>
#include <vector>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int maxWidth = 0;
    vector<vector<int>> dp;
    for (int i = 0; i < matrix.size(); i++) {
        vector<int>line;
        dp.push_back(line);
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == '1')
                dp[i].push_back(1);
            else
                dp[i].push_back(0);
        }
    }

    for (int i = matrix.size() - 2; i >= 0; i--)
        for (int j = matrix[0].size() - 2; j >= 0; j--) {
            if (dp[i][j])
                dp[i][j] = min(dp[i + 1][j + 1], min(dp[i + 1][j], dp[i][j + 1])) + 1;
            else
                dp[i][j] = 0;
            maxWidth = max(maxWidth, dp[i][j]);
        }

    return maxWidth;
}



int main() {

    return 0;
}
