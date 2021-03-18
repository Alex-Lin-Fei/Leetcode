#include <iostream>
#include <vector>
using namespace std;


//overtime
void dfs(vector<vector<bool>> & isPalindrome, string & s, int i, int & len, int & ans) {
    if (i == s.length()) {
        ans = min(ans, len);
        cout << '*';
    }

    else {
        for (int j = s.length() - 1; j >= i; j--) {
            if (len + 1 < ans && isPalindrome[i][j]) {
                len++;
                dfs(isPalindrome, s, j + 1, len, ans);
                len--;
            }
        }
    }
}


int minCut(string s) {
    vector<vector<bool>> isPalindrome(s.length(), vector<bool>(s.length()));
//    int ans = s.length();
//    int len = 0;

    vector<int> dp(s.length(), s.length());

    for (int j = 0; j < s.length(); j++) {
        for (int i = j; i < s.length(); i++)
            isPalindrome[i][j] = true;
    }

    for (int l = 2; l <= s.length(); l++) {
        for (int i = 0; i <= s.length() - l; i++) {
            isPalindrome[i][i + l - 1] = isPalindrome[i + 1][i + l - 2] & (s[i] == s[i + l - 1]);
        }
    }

    if (isPalindrome[0][s.length() - 1])
        return 0;
//    dfs(isPalindrome, s, 0, len, ans);

    for (int right = 0; right < s.length(); right++) {
        if (isPalindrome[0][right])
            dp[right] = 1;
        else {
            for (int left = 0; left < right; left++) {
                if (isPalindrome[left + 1][right]) {
                    dp[right] = min(dp[right], dp[left] + 1);
                }
            }
        }
    }

//    return ans - 1;
    return dp[s.length()-1]-1;
}

int main() {
    std::cout << minCut("apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp") << std::endl;

    return 0;
}
