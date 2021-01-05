#include <iostream>
using namespace std;

string removeKdigits(string num, int k) {
    if (k == num.size())
        return "0";
    int idx;
    for (int i = 0; i < k; i++) {
        idx = 0;
        while (idx < num.size() - 1 && num[idx] <= num[idx + 1])
            idx++;
        num.erase(num.begin() + idx);
    }
    idx = 0;
    while (idx < num.size() && num[idx] == '0')
        idx++;

    return idx == num.size() ? "0" : num.substr(idx, num.size() - idx);
}

int main() {
    cout << removeKdigits("112", 1);
    return 0;
}
