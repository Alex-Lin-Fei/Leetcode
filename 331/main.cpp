#include <iostream>
#include <stack>
using namespace std;

bool isValidSerialization(string preorder) {
    int i = 0;
    stack<int> stk;

    stk.push(1);


    while (i < preorder.size()) {
        if (stk.empty())
            return false;
        if (preorder[i] == ',') {
            i++;
            continue;
        }
        else if (preorder[i] == '#') {
            stk.top()--;
            if (stk.top() == 0)
                stk.pop();
            i++;
        } else {
            while (i < preorder.size() && preorder[i] != ',')
                i++;
            stk.top()--;
            if (stk.top() == 0)
                stk.pop();
            stk.push(2);
        }
    }

    return stk.empty();
}

int main() {
    cout << isValidSerialization("9,3,4,#,#,#,1,#,#,2,#,6,#,#");

    return 0;
}
