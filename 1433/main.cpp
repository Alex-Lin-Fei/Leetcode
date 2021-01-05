#include <iostream>
#include <algorithm>
using namespace std;

bool checkIfCanBreak(string s1, string s2) {
    char str1[s1.size()];
    char str2[s2.size()];
    for (auto i = 0; i < s1.size(); i++) {
        str1[i] = s1[i];
        str2[i] = s2[i];
    }

    sort(str1, str1 + s1.size());
    sort(str2, str2 + s2.size());
    bool x = false;
    bool y = false;
    for (int i = 0; i < s1.size(); i++) {
        if (str1[i] < str2[i]) {
            y = true;
        } else if (str1[i] > str2[i])
            x = true;
    }

    return !(x && y);
}

int main() {
    cout << checkIfCanBreak("adc", "eba");
    return 0;
}
