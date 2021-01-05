#include <iostream>
#include <vector>
using namespace std;

int expand(string& s, int left, int right) {
    int l = left;
    int r = right;
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
        l--;
        r++;
    }
    return r - l - 1;
}

string longestPalindrome(string s) {
    if (s.size() < 2)
        return s;
    int start = 0;
    int end = 0;
    for (int i = 0; i < s.size(); i++) {
        int len = max(expand(s, i, i), expand(s, i, i + 1));
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substr(start, end - start + 1);
}


int main() {
    std::cout << longestPalindrome("aba") << std::endl;
    return 0;
}
