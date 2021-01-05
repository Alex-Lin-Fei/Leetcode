#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string reorganizeString(string S) {
    vector<int> count(26);
//    统计每个字母出现的次数
    for (auto &ch: S)
        count[ch - 'a']++;

//    判断是否可以重新排布
    int maxLen = *max_element(count.begin(), count.end());
    if (maxLen > (S.length() + 1) / 2)
        return "";
//    隔一位放置一个字母
    int odd = 1, even = 0;
    for (int i = 0; i < 26; i++) {
        while (count[i] > 0 && count[i] < S.length() / 2+1 && odd < S.length()) {
            S[odd] = (char) ('a' + i);
            count[i]--;
            odd += 2;
        }

        while (count[i] > 0 && even < S.length()) {
            S[even] = (char) ('a' + i);
            count[i]--;
            even += 2;
        }
    }
    return S;
}

int main() {
    std::cout << reorganizeString("vvvlo") << std::endl;
    return 0;
}
