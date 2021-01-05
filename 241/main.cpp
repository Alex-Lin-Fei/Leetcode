#include <iostream>
#include <vector>
using namespace std;

vector<int> diffWaysToCompute(string input) {
    vector<int> way;

    for (int i = 1; i < input.size() - 1; i++) {
        char ch = input[i];
        if (ch == '+' || ch == '-' || ch == '*') {
            vector<int> left = diffWaysToCompute(input.substr(0, i));
            vector<int> right = diffWaysToCompute(input.substr(i + 1));
            for (auto &a: left)
                for (auto &b: right) {
                    switch (ch) {
                        case '+':
                            way.push_back(a + b);
                            break;
                        case '-':
                            way.push_back(a - b);
                            break;
                        case '*':
                            way.push_back(a * b);
                            break;
                        default:
                            break;
                    }
                }
        }
    }
    if (way.empty())
        way.push_back(stoi(input));
    return way;
}

int main() {
    int a = 1, b = 2;


    return 0;
}
