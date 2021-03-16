#include <iostream>
#include <vector>
using namespace std;

void dfs(string & s, int i, vector<vector<bool>>& isPalindrome, vector<string> & tmp, vector<vector<string>> & ans) {
    if (i == s.length()) {
        ans.push_back(tmp);
    }
    else {
        for (int j = i; j < s.length(); j++) {
            if (isPalindrome[i][j]) {
                tmp.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1, isPalindrome, tmp, ans);
                tmp.pop_back();
            }
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> tmp;

    vector<vector<bool>> isPalindrome(s.length(), vector<bool>(s.length(), false));

    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < s.length(); j++) {
            isPalindrome[i][j] = i >= j;
        }
    }

//    判断各子串是否为palindrome
    for (int l = 2; l <= s.length(); l++) {
        for (int i = 0; i <= s.length() - l; i++)
            isPalindrome[i][i + l - 1] = isPalindrome[i + 1][i + l - 2] & (s[i] == s[i + l - 1]);
    }

    dfs(s, 0, isPalindrome, tmp, ans);

    for (const auto &t: ans) {
        for (const string &str: t)
            cout << str << ' ';
        cout << endl;
    }

    return ans;
}

int main() {
    partition("aba");

    return 0;
}
