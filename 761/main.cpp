#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string makeLargestSpecial(string S) {
    vector<string> strs;
    int pos = 0;
    int cnt = 0;

    for (int i = 0; i < S.size(); i++) {
        cnt = S[i] == '1' ? cnt + 1 : cnt - 1;
        if (cnt == 0) {
            strs.push_back('1' + makeLargestSpecial(S.substr(pos + 1, i - pos - 1)) + '0');
            pos = i + 1;
        }
    }
    string ans;
    sort(strs.begin(), strs.end(), greater<string>());
    for (auto &str: strs)
        ans += str;
    return ans;
}

int main() {
    std::cout << makeLargestSpecial("11011000") << std::endl;
    return 0;
}
