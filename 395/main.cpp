#include <iostream>
#include <vector>
using namespace std;

int longestSubstring(string s, int k) {
    int ansLen = 0;

    for (int i = 1; i <= min(26, (int)s.length()); i++) {
        int total = 0;
        int less = 0;
        vector<int> count(26);
        int left = 0, right = 0;

        while (right < s.length()) {
            count[s[right] - 'a']++;
            if (count[s[right] - 'a'] == 1) {
                total++;
                less++;
            }
            if (count[s[right] - 'a'] == k) {
                less--;
            }

            while (total > i) {
                count[s[left] - 'a']--;
                if (count[s[left] - 'a'] == 0) {
                    total--;
                    less--;
                }
                if (count[s[left] - 'a'] == k - 1) {
                    less++;
                }

                left++;
            }

            if (less == 0) {
                ansLen = max(ansLen, right - left + 1);
            }

            right++;
        }
    }

    return ansLen;
}

int main() {
    std::cout << longestSubstring("a", 1) << std::endl;
    return 0;
}
