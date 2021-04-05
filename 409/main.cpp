#include <iostream>
#include <map>

using namespace std;

int longestPalindrome(string s) {
    map<char, int> count;
    int len = 0;

    for (auto &ch: s)
        count[ch]++;

    for (auto &item: count) {
        len += item.second / 2 * 2;
        if (item.second % 2 && len % 2 == 0)
            len++;
    }


    return len;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
