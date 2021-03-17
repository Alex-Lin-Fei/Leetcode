#include <iostream>
#include <vector>
using namespace std;

int equalSubstring(string s, string t, int maxCost) {
    vector<int> count(s.length());
    int sum = 0;
    int len = 0;

    for (int i = 0; i < count.size(); i++)
        count[i] = abs(s[i] - t[i]);

    int left = 0, right = 0;
    while (right < s.length()) {
        while (sum <= maxCost && right < s.length()) {
            len = max(len, right - left);
            sum += count[right++];
        }

        if (right >= s.length() && sum <= maxCost) {
            len = max(len, right - left);
        }

        while (sum > maxCost && left < right) {
            sum -= count[left++];
            if (sum <= maxCost)
                len = max(len, right - left);
        }

    }

    return len;
}

int main() {
    std::cout << equalSubstring("abcd",
                                "acde",
    3) << std::endl;
    return 0;
}
