#include <iostream>
#include <vector>
using namespace std;

bool isMatch(string s, string p) {
    vector<vector<int>>dp(s.size() + 1, vector<int>(p.size() + 1, 0));
    for (int i = dp.size() - 1; i >= 0; i--) {
        for (int j = dp[0].size() - 1; j >= 0; j--) {
            if (i == dp.size() - 1 && j == dp[0].size() - 1)
                dp[i][j] = 1;
            else {
                bool first = (i < s.size() && (p[j] == s[i] || p[j] == '.'));
                if (j < p.size() - 1 && p[j + 1] == '*')
                    dp[i][j] = dp[i][j + 2] || (first && dp[i + 1][j]);
                else if (j < p.size())
                    dp[i][j] = first && dp[i + 1][j + 1];
            }
        }
    }
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[0].size(); j++) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    return dp[0][0];
}

int main() {
    std::cout << isMatch("ab", ".*") << std::endl;
    return 0;
}
