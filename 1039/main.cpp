#include <iostream>
#include <vector>
using namespace std;

int minScoreTriangulation(vector<int>& A) {
    vector<vector<int>> dp(A.size(), vector<int>(A.size(), INT16_MAX));
    for (int i = 0; i < dp.size(); i++)
        dp[i][i] = 0;
    for (int d = 2; d < dp.size(); d++) {
        for (int i = 1; i < dp.size() - d + 1; i++) {
            int j = i + d - 1;
            dp[i][j] = dp[i+1][j] + A[i - 1] * A[i] * A[j];
            for (int k = i + 1; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + A[i - 1] * A[k] * A[j]);
        }
    }

    return dp[1][A.size() - 1];
}

int main() {
    vector<int> A;
    A.push_back(1);
    A.push_back(3);
    A.push_back(1);
    A.push_back(4);
    A.push_back(1);
    A.push_back(5);
//    A.push_back(3);
//    A.push_back(7);
//    A.push_back(4);
//    A.push_back(5);

    std::cout << minScoreTriangulation(A) << std::endl;
    return 0;
}
