#include <iostream>
#include <vector>
#include <stack>
#include <regex>

using namespace std;

//
//int calculate(string s) {
//    string pattern = " ";
//    regex re(pattern);
//
//    s = regex_replace(s, re, "");
//
//    stack<char> operators;
//    stack<int> operand;
//    int i = 0;
//
//
//    while (i < s.length()){
//        char ch = s[i];
////        转为数字
//        if (isalnum(ch)) {
//            int num = 0;
//            while (i < s.length() && isalnum(s[i])) {
//                num = num * 10 + s[i] - '0';
//                i++;
//            }
//            operand.push(num);
//        } else if (ch == '(') {
//            operators.push(ch);
//            i++;
//        } else if (ch == '-' || ch == '+') {
//            if (!operators.empty() && operators.top() != '(') {
//                int b = operand.top();
//                operand.pop();
//                operand.top() = operand.top() + (operators.top() == '+' ? 1 : -1) * b;
//                operators.pop();
//            }
//            operators.push(ch);
//            i++;
//        }
//        else {
//            while (!operators.empty() && operators.top() != '(') {
//                int b = operand.top();
//                operand.pop();
//                operand.top() = operand.top() + (operators.top() == '+'? 1: -1) * b;
//                operators.pop();
//            }
//            if (!operators.empty())
//                operators.pop();
//
//            i++;
//        }
//    }
//
//    while (!operators.empty()) {
//        int b = operand.top();
//        operand.pop();
//        operand.top() = operand.top() + (operators.top() == '+'? 1: -1) * b;
//        operators.pop();
//    }
//
//    return operand.top();
//}


void pre(stack<int> &stk, map<int, int> &se, string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            stk.push(i);
        else if (s[i] == ')') {
            se[stk.top()] = i;
            stk.pop();
        }
    }
}


int calculateSum(string s, map<int, int> &se, int start, int end) {
    int sum = 0;
    int flag = 1;

    while (start <= end) {
        if (s[start] == '(') {
            sum += flag * calculateSum(s, se, start + 1, se[start] - 1);
            start = se[start];
        } else if (s[start] == '-')
            flag = -1;
        else if (s[start] == '+')
            flag = 1;
        else if (isalnum(s[start])) {
            int num = 0;
            while (start <= end && isalnum(s[start])) {
                num = num * 10 + (s[start] - '0');
                start++;
            }
            start--;
            sum += flag * num;
        }

        start++;
    }

    return sum;
}

int calculate(string s) {
    stack<int> stk;
    map<int, int> se;

    pre(stk, se, s);

    return calculateSum(s, se, 0, s.size() - 1);
}


int main() {
    cout << calculate("1-(+1+1)");

    return 0;
}
