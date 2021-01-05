#include <iostream>
#include <vector>
using namespace std;

int countSquares(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].size() == 0)
        return 0;
    vector<vector<int>>dp(matrix.size(), vector<int>(matrix[0].size()));
    int sum = 0;
    for (int i = 0; i < matrix.size(); i++) {
        dp[i][0] = matrix[i][0];
        sum += dp[i][0];
    }
    for (int j = 1; j < matrix[0].size(); j++) {
        dp[0][j] = matrix[0][j];
        sum += dp[0][j];
    }
    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 1; j < matrix[0].size(); j++) {
            if (!matrix[i][j])
                dp[i][j] = 0;
            else
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
            sum += dp[i][j];
        }
    }
    return sum;
}

int main() {
    vector<vector<int>>matrix;
    for (int i = 0; i < 3;i++) {
        vector<int>l;
        matrix.push_back(l);
        for (int j = 0; j < 3; j++) {
            int a;
            cin >> a;
            matrix[i].push_back(a);
        }
    }
    std::cout << countSquares(matrix) << std::endl;
    return 0;
}
