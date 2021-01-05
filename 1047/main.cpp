#include <iostream>
#include <stack>
#include <algorithm>
using std::stack;
using std::string;
using std::endl;
using std::cout;
using std::cin;


string removeDuplicates(string S) {
    stack<char> s;
    for (char & i : S) {
        if (!s.empty() && s.top() == i)
            s.pop();
        else
            s.push(i);
    }
    string res;
    while (!s.empty()) {
        res += s.top();
        s.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
