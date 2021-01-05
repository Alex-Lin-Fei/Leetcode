#include <iostream>
#include <vector>
using namespace std;

int dieSimulator(int n, vector<int>& rollMax) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(7, vector<int>(16)));
    int mod = 1e9 + 7;
    for (int i = 1; i <= 6; i++)
        dp[0][i][1] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= 6; j++) {
            for (int k = 1; k <= 6; k++) {
                if (j == k) {
                    for (int t = 1; t <= rollMax[k-1]; t++) {
                        dp[i][j][t+1] = dp[i-1][j][t];
                        dp[i][j][t+1] %= mod;
                    }
                }
                else {
                    for (int t = 1; t <= rollMax[k-1]; t++) {
                        dp[i][j][1] += dp[i-1][k][t];
                        dp[i][j][1] %= mod;
                    }
                }
            }
        }

    }
    int sum = 0;
    for (int i = 1; i <= 6; i++)
        for (int j = 1; j  <= rollMax[i-1]; j++)
        {
            sum = (sum + dp[n-1][i][j]) % mod;
        }
    return sum;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
