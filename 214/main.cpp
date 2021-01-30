#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isPalindrome(string s) {
    string tmp = s;
    reverse(tmp.begin(), tmp.end());

    return tmp == s;
}
//超时
/*
string shortestPalindrome(string s) {
    // idx是当前子串最后一个字符的索引
    string ans;

    int idx = s.size() - 1;
    while (idx>=0 && !isPalindrome(s.substr(0, idx+1)))
        idx--;
    int l = s.size()-1;

    while (l != idx) {
        ans += s[l--];
    }
    ans += s;

    return ans;
}
*/

//Manacher
int manacher(string& s) {
//    定义辅助数组
    vector<char> chs(s.size() * 2 + 1);
    for (int i = 0; i < chs.size(); i++) {
        chs[i] = i % 2 ? s[i / 2] : '#';
    }
    vector<int> pArr(chs.size());

    int R = -1, C = -1, maxn = 0;

    for (int i = 0; i < chs.size(); i++) {
        pArr[i] = R > i ? min(R - i, pArr[2 * C - i]) : 1;
        while (i + pArr[i] < chs.size() && i - pArr[i] > -1) {
            if (chs[i + pArr[i]] == chs[i - pArr[i]])
                pArr[i]++;
            else
                break;
        }

        if (i + pArr[i] > R) {
            R = i + pArr[i];
            C = i;
        }
        if (pArr[i] - 1 == i)
            maxn = max(maxn, pArr[i]);
    }
    return maxn-1;
}

string shortestPalindrome(string &s) {
    string ans;

    int len = manacher(s);
    int idx = s.size() - 1;
    while (idx >= len)
        ans += s[idx--];
    ans += s;

    return ans;
}

int main() {
    string s = "abcd";
    cout << shortestPalindrome(s);

    return 0;
}
