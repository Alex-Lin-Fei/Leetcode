#include <iostream>
using namespace std;

string getStr(string & s) {
    string res;
    for (auto & ch: s) {
        if (isalpha(ch))
            res += tolower(ch);
        else if (isdigit(ch))
            res += ch;
    }
    return res;
}

string reverseStr(string & s) {
    string res;
    for (int i = s.size() - 1; i >= 0; i--)
        res += tolower(s[i]);
    return res;
}

bool isPalindrome(string s) {
    s = getStr(s);
    string sR = reverseStr(s);
    return s == sR;
}

int main() {
    string s = "Hello, World!";
    cout << isPalindrome(s) << std::endl;
    return 0;
}
