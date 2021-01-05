#include <iostream>
#include <map>
using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.length() != t.length())
        return false;

    map<char, char> stot;
    map<char, char> ttos;
    for (int i = 0; i < s.length(); i++) {
        if (!stot.count(s[i]) && !ttos.count(t[i])) {
            stot[s[i]] = t[i];
            ttos[t[i]] = s[i];
        } else if (stot.count(s[i]) && stot[s[i]] != t[i]
                   || ttos.count(t[i]) && ttos[t[i]] != s[i])
            return false;
    }
    return true;
}

int main() {
    std::cout << isIsomorphic("paper", "titie") << std::endl;
    return 0;
}
