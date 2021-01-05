#include <iostream>
#include <vector>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    for (auto &i : dp)
        i[0] = 0;
    for (int &i : dp[0])
        i = 0;
    for (int i = 1; i < dp.size(); i++)
        for (int j = 1; j < dp[0].size(); j++) {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    return dp[text1.size()][text2.size()];
}


int main() {
    string t1 = "abc";
    string t2 = "abc";
    cout << longestCommonSubsequence(t1, t2);
    return 0;
}
