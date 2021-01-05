#include <iostream>
#include <vector>

using namespace std;

bool track(vector<int> &fibonacci, string &S, int idx, int pre, int sum) {
    if (idx == S.size())
        return fibonacci.size() >= 3;
    else {
        long cur = 0;
        for (int i = idx; i < S.length(); i++) {
            if (i > idx && S[idx] == '0')
                break;
            cur = cur * 10 + S[i] - '0';
            if (cur > INT32_MAX)
                break;

            else if (fibonacci.size() >= 2) {
                if (cur < sum)
                    continue;
                else if (cur > sum)
                    break;
            }
            fibonacci.push_back(cur);
            if (track(fibonacci, S, i + 1,cur, cur + pre))
                return true;
            fibonacci.pop_back();
        }
    }
    return false;
}

vector<int> splitIntoFibonacci(string S) {
    vector<int> fibonacci;
    cout << track(fibonacci, S, 0, 0, 0)<<endl;

    return fibonacci;
}

int main() {
    auto fibonacci = splitIntoFibonacci("0123");
    for (auto& i: fibonacci)
        cout << i << ' ';
    cout << endl;
}