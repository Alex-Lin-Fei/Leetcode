#include <iostream>
using namespace std;

int minimumLength(string s) {
    int r = s.size() - 1;
    int l = 0;


    while (l < r && s[l] == s[r]) {
        char ch = s[l];
        while (l < r && s[l] == ch)
            l++;
        while (r > l && s[r] == ch)
            r--;
        if (l == r && s[r] == ch)
            return 0;
    }

    return r - l + 1;
}


int main() {
    std::cout << minimumLength("cac") << std::endl;
    return 0;
}
