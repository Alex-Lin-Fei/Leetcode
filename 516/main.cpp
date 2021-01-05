#include <iostream>
#include <vector>
using namespace std;

int longestPalindromeSubseq(string s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

    for (int i = 0; i < dp.size(); i++) {
        dp[i][i] = 1;
    }

    for (int i = dp.size() - 1; i >= 0; i--) {
        for (int j = i + 1; j < dp[0].size(); j++)
            dp[i][j] = (s[i] == s[j]) ? dp[i + 1][j - 1] + 2 : max(dp[i + 1][j], dp[i][j - 1]);
    }
    return dp[0][s.size() - 1];
}
int main() {
    std::cout << longestPalindromeSubseq("bbbab") << std::endl;
    return 0;
}
