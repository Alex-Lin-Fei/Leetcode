#include <iostream>
#include <queue>
using namespace std;

class MaxQueue {
    queue<int> que;
    deque<int> help;
public:
    MaxQueue() {

    }

    int max_value() {
        return help.empty() ? -1: help.front();
    }

    void push_back(int value) {
        que.push(value);
        while (!help.empty() && value > help.back()){
            help.pop_back();
        }
        help.push_back(value);
    }

    int pop_front() {
        if(que.empty())
            return -1;
        int e = que.front();
        que.pop();
        if (e == help.front())
            help.pop_front();
        return e;
    }
};


int main() {
    queue<int> que;
    que.pop();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
