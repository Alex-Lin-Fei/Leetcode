#include <iostream>
using namespace std;

bool isNum(string num) {
    if (!num.size())
        return false;
    int idx = 0;

    while (idx < num.size() && isdigit(num[idx]))
        idx++;
    return idx == num.size();
}

bool isInteger(string s) {
    if (s.size() == 0)
        return false;

    int idx = 0;
    if (s[idx] == '+' || s[idx] == '-')
        idx++;
    if (idx == s.size())
        return false;

    return isNum(s.substr(idx, s.size()-idx));
}

bool isDecimal(string s) {
    if (s.size() == 0)
        return false;
    if (s[0] == '-' || s[0] == '+')
        s = s.substr(1, s.size() - 1);

    int idx = s.find(".");
    if (idx < s.size()) {
        if (s.substr(0, idx) != "" && !isInteger(s.substr(0, idx)))
            return false;
        if (idx < s.size() -1 && !isdigit(s[idx+1]))
            return false;
        if (s.substr(0, idx) == "" && s.substr(idx+1, s.size()-idx-1) == "")
            return false;
        return s.substr(idx+1, s.size()-idx-1) == "" || isInteger(s.substr(idx+1, s.size()-idx-1));
    }

    return false;
}

bool isSci(string s) {
    int idx = -1;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (isalpha(c) && tolower(c) != 'e')
            return false;
        if (isalpha(c) && tolower(c) == 'e') {
            if (idx == -1)
                idx = i;
            else
                return false;
        }
    }
    if (idx == s.size() - 1)
        return false;
    return (isDecimal(s.substr(0, idx))||isInteger(s.substr(0, idx)))
           && ( isInteger(s.substr(idx+1, s.size()-idx-1)));
}

bool isNumber(string s) {
//    去除多余空格
    int pre = 0;
    int post = s.size() - 1;
    while (pre < s.size() && s[pre] == ' ')
        pre++;
    if (pre == s.size())
        return false;

    while (post >= 0 && s[post] == ' ')
        post--;
    s = s.substr(pre, post-pre+1);
    return isInteger(s) || isDecimal(s) || isSci(s);
}

int main() {
    string s = "4.9e3.";
    cout << isNumber(s);
    return 0;

}
