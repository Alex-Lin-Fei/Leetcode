#include <iostream>
#include <map>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size())
        return false;

    map<char, int> ms, mt;

    for (auto &ch: s)
        ms[ch]++;
    for (auto &ch: t)
        mt[ch]++;
    for (auto &i: ms) {
        if (!mt.count(i.first) || mt[i.first] != i.second)
            return false;
    }
    return true;
}

int main() {
    cout << isAnagram("anagram", "nagaraam")<<endl;
    return 0;
}
