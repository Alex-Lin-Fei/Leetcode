#include <iostream>
#include <set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int l = 0, r = 0;
    int ans = 0;
    set<char> once;

    while (r < s.length()) {
        if (!once.count(s[r]))
            once.insert(s[r++]);
        else {
            ans = max(ans, r - l);
            while (l < r) {
                once.erase(s[l]);
                l++;
                if (s[l-1] == s[r])
                    break;
            }
            once.insert(s[r++]);
        }
    }

    ans = max(ans, r - l);

    return ans;
}

int main() {
    std::cout << lengthOfLongestSubstring("abcdeeabcdfg") << std::endl;
    return 0;
}
