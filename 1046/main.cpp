#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> que;

    for (auto &stone: stones)
        que.push(stone);

    while (que.size() > 1) {
        int x = que.top();
        que.pop();
        int y = que.top();
        que.pop();

        if (x != y)
            que.push(x - y);
    }
    return que.empty() ? 0 : que.top();
}

int main() {
   vector<int> stones{2,7,4,1,8,1};
   cout << lastStoneWeight(stones);

    return 0;
}
