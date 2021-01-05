#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int toNum(string& s) {
    int i = 0;
    int num = 0;
    while (!isdigit(s[i]))
        i++;
    while (i < s.size() && isdigit(s[i])) {
        num = num * 10 + s[i] - '0';
        i++;
    }
    if (s[0] == '-')
        num *= -1;
    return num;
}

int evalRPN(vector<string>& tokens) {
    stack<int>operands;

    for (auto& s: tokens) {
        if (s == "+" || s == "-" || s == "*" || s == "/")
        {
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
            switch (s[0]) {
                case '+':
                    a += b;
                    break;
                case '-':
                    a -= b;
                    break;
                case '*':
                    a *= b;
                    break;
                case '/':
                    a /= b;
                    break;
                default:
                    break;
            }
            operands.push(a);
        }
        else
            operands.push(toNum(s));
    }
    return operands.top();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
