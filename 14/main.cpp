#include <iostream>
#include <vector>
using namespace std;

string longestPrefix(string str1, string str2) {
    int len = min(str1.length(), str2.length());
    int index = 0;
    string ans;
    while (index < len && str1[index] == str2[index]) {
        ans += str1[index];
        index++;
    }
    return ans;
}

string longestCommonPrefix(vector<string>& strs) {
    if (!strs.size())
        return "";
    string ans = strs[0];
    for (int i = 1; i < strs.size(); i++) {
        ans = longestPrefix(ans, strs[i]);
        if (ans == "")
            break;
    }
    return ans;
}

int main() {
    vector<string> strs;
    strs.emplace_back("flower");
    strs.emplace_back("flow");
    strs.emplace_back("flight");
    cout << longestCommonPrefix(strs);

    return 0;
}
