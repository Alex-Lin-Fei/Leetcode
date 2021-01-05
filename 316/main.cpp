#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

string removeDuplicateLetters(string s) {
    map<char, int> count;
    set<char> vis;

    for (auto &i: s)
        count[i]++;
    string ans;
    for (auto &ch: s) {
//        未加入
        if (!vis.count(ch)) {
            while (!ans.empty() && ans.back() > ch) {
                if (count[ans.back()] > 0) {
                    vis.erase(ans.back());
                    ans.pop_back();
                } else
                    break;
            }
            ans.push_back(ch);
            vis.insert(ch);
        }
        count[ch]--;
    }
    return ans;
}


int main() {
    std::cout << removeDuplicateLetters("bcabc") << std::endl;
    return 0;
}
