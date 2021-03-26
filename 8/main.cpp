#include <iostream>
using namespace std;

int myAtoi(string s) {
    long res = 0;
    int ans = 0;
    int flag = 1;

    int idx = 0;

    while (idx < s.length() && s[idx] == ' ')
        idx++;


    if (idx < s.length() && !isalnum(s[idx])) {
        if (s[idx] == '-' || s[idx] == '+') {
            flag = (s[idx] == '-' ? -1 : 1);
            idx++;
        } else
            return 0;
    }

    while (idx < s.length() && isalnum(s[idx]) == 4) {
        if (res > INT32_MAX / 10 || res == INT32_MAX /10 && s[idx] - '0' > 7)
            return flag == 1 ? INT32_MAX : INT32_MIN;
        res = res * 10 + (s[idx] - '0');
        idx++;
    }
    ans = (int) (res * flag);

    return ans;
}

int main() {
    std::cout << myAtoi("2147483648") << std::endl;

    return 0;
}
