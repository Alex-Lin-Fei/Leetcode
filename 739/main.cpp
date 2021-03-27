#include <iostream>
#include <vector>
#include <stack>
using namespace std;


vector<int> dailyTemperatures(vector<int>& T) {
    stack<int> stk;
    vector<int> days(T.size());

    for (int i = T.size() - 1; i >= 0; i--) {
        while (!stk.empty() && T[i] >= T[stk.top()])
            stk.pop();
        if (!stk.empty())
            days[i] = stk.top() - i;
        stk.push(i);
    }
    for (auto& i: days)
        cout << i << ' ';
    cout << endl;

    return days;
}

int main() {
    vector<int> T {73, 74, 75, 71, 69, 72, 76, 73};
    dailyTemperatures(T);

    return 0;
}
