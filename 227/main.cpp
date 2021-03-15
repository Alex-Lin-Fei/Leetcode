#include <iostream>
#include <stack>
using namespace std;

int compute(string& s, stack<int>& nums, stack<char> & opts) {
    int i = 0;

    while (i < s.length()) {
        char ch = s[i];
        switch (ch) {
            case ' ':
                break;
            case '+':
            case '-': {
                while (!opts.empty() && opts.top() != '(') {
                    int tmp = nums.top();
                    nums.pop();
                    switch (opts.top()) {

                        case '+':
                            nums.top() += tmp;
                            break;
                        case '-':
                            nums.top() -= tmp;
                            break;
                        case '*':
                            nums.top() *= tmp;
                            break;
                        case '/':
                            nums.top() /= tmp;
                            break;
                    }
                    opts.pop();
                }
                opts.push(ch);
            }
                break;
            case '*':
            case '/': {
                while (!opts.empty() && (opts.top() == '*' || opts.top() == '/')) {
                    int tmp = nums.top();
                    nums.pop();
                    if (opts.top() == '*')
                        nums.top() *= tmp;
                    else
                        nums.top() /= tmp;
                    opts.pop();
                }
                opts.push(ch);
            }
                break;
            case '(':
                opts.push(ch);
                break;
            case ')': {
                while (!opts.empty() && opts.top() != '(') {
                    int tmp = nums.top();
                    nums.pop();

                    switch (opts.top()) {

                        case '+':
                            nums.top() += tmp;
                            break;
                        case '-':
                            nums.top() -= tmp;
                            break;
                        case '*':
                            nums.top() *= tmp;
                            break;
                        case '/':
                            nums.top() /= tmp;
                            break;
                    }
                    opts.pop();
                }
                opts.pop();
            }
                break;
            default: {
                int num = 0;
                while (i < s.length() && isalnum(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                nums.push(num);
            }
                break;
        }
        i++;
    }

    while (!opts.empty()) {
        int tmp = nums.top();
        nums.pop();

        switch (opts.top()) {
            case '+':
                nums.top() += tmp;
                break;
            case '-':
                nums.top() -= tmp;
                break;
            case '*':
                nums.top() *= tmp;
                break;
            case '/':
                nums.top() /= tmp;
                break;
        }
        opts.pop();
    }
    return nums.top();
}


int calculate(string s) {
//    预处理
    string ans;
    for (char ch : s) {
        if ((ch == '+' || ch == '-')
        && (ans.length() == 0 || ans[ans.length()-1] == '(')) {
            ans += '0';
        }
        ans += ch;
    }
    cout << ans << endl;

    stack<int> nums;
    stack<char> opts;

    return compute(ans, nums, opts);
}

int main() {
    cout << calculate(  " 2*3 + 4 ");
    return 0;
}
