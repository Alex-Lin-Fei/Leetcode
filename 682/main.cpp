#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

int toDigit(string& s) {
    int res = 0;
    int i;
    if (s[0] == '-')
        i = 1;
    else
        i = 0;
    for (; i < s.length(); i++) {
        res *= 10;
        res += s[i] - '0';
    }
    if (s[0] == '-')
        res *= -1;
    return res;
}

int calPoints(vector<string>& ops) {
    stack<int>scores;
    int sumScores = 0;
    for (auto& ch: ops) {
        if (ch == "+") {
            int t1 = scores.top();
            scores.pop();
            int t2 = scores.top();
            scores.push(t1);
            scores.push(t1 + t2);
            sumScores += scores.top();
        } else if (ch == "D") {
            scores.push(scores.top() * 2);
            sumScores += scores.top();
        } else if (ch == "C") {
            sumScores -= scores.top();
            scores.pop();
        } else {
            scores.push(toDigit(ch));
            sumScores += scores.top();
        }

    }
    return sumScores;
}

int main() {
    vector<string> s;
    s.push_back("5");
    s.push_back("-2");
    s.push_back("4");
    s.push_back("C");
    s.push_back("D");
    s.push_back("9");
    s.push_back("+");
    s.push_back("+");
    cout << calPoints(s) << endl;

    return 0;
}
