#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class StackOfPlates {
private:
    int cap;
    vector<stack<int>>sv;
public:
    StackOfPlates(int cap) {
        this->cap = cap;
    }

    void push(int val) {
//        需要新建一个栈
        if (cap == 0)
            return;
        if (sv.empty() || sv.back().size() == cap) {
            stack<int> newS;
            sv.push_back(newS);
        }
        if (cap != 0)
            sv.back().push(val);
    }

    int pop() {
        if (sv.empty())
            return -1;
        int val = sv.back().top();
        sv.back().pop();
        if (sv.back().empty())
            sv.pop_back();

        return val;
    }

    int popAt(int index) {
        if (index >= sv.size())
            return -1;
        int val = sv[index].top();
        sv[index].pop();
//        删除空栈
        if (sv[index].empty()) {
            for (int i = index; i < sv.size() - 1; i++)
                sv[i] = sv[i + 1];
            sv.pop_back();
        }

        return val;
    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */


int main() {
    StackOfPlates s = StackOfPlates(2);

    return 0;
}
