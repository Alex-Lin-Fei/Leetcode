#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> s;
    int idx = 0;

    for (int i : popped) {
        while (s.empty() || s.top() != i) {
            if (idx == pushed.size())
                return false;
            s.push(pushed[idx++]);
        }
        s.pop();
    }

    return s.empty();
}

int main() {
    vector<int> pushed{1,2,3,4,5};
    vector<int> poped{4,5,3,2,1};
    std::cout << validateStackSequences(pushed, poped) << std::endl;

    return 0;
}
