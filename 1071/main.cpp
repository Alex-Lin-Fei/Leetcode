#include <iostream>
using namespace std;

//默认a > b
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool check(string & str, string & gcdStr) {
    int times = str.length() / gcdStr.length();
    string ans;

    while (times--)
        ans += gcdStr;

    return ans == str;
}

string gcdOfStrings(string str1, string str2) {
//    求str1.length 和 str2.length 的最大公约数gcd
//    并获取gcd长的前缀 判断是否是两个字符串的因串

    int len = gcd(str1.length(), str2.length());
    string gcdStr = str2.substr(0, len);

    if (check(str1, gcdStr) && check(str2, gcdStr))
        return gcdStr;
    return "";
}

int main() {
    std::cout << gcdOfStrings("LEETCODE", "AB") << std::endl;
    return 0;
}
