#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int longestValidParentheses(string s) {
    int len = 0;
    stack<int> stk;
    stk.push(-1);

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            stk.push(i);
        else {
            stk.pop();
            if (stk.empty())
                stk.push(i);
            else {
                len = max(len, i-stk.top());
            }
        }
    }
    return len;
}

int main() {
    std::cout << longestValidParentheses(")()())") << std::endl;
    return 0;
}
