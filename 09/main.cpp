#include <iostream>
#include <stack>
using namespace std;


class CQueue {
    stack<int>s;
    stack<int>t;
public:
    CQueue() {
        while (!s.empty())
            s.pop();
        while (!t.empty())
            t.pop();
    }

    void appendTail(int value) {
        s.push(value);
    }

    int deleteHead() {
        if (t.empty()) {
            while (!s.empty()) {
                t.push(s.top());
                s.pop();
            }
        }
        if (t.empty())
            return -1;
        else {
            int deleteItem = t.top();
            t.pop();
            return deleteItem;
        }
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
