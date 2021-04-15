#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool halvesAreAlike(string s) {
    int idx = 0;
    int sum = 0;

    set<char> vowels{'a', 'e', 'i', 'o', 'u'};

    while (idx < s.length()) {
        if (vowels.count(tolower(s[idx]))) {
            if (idx < s.length() / 2)
                sum++;
            else {
                sum--;
                if (sum < 0)
                    return false;
            }
        }
    }
    return sum == 0;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
