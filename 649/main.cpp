#include <iostream>
#include <queue>
using namespace std;


string predictPartyVictory(string senate) {
    queue<int> radiant, dire;

//    先将r d的索引入队列
    for (int i = 0; i < senate.size(); i++) {
        if (senate[i] == 'R')
            radiant.push(i);
        else
            dire.push(i);
    }

    while (!radiant.empty() && !dire.empty()) {
        int r = radiant.front();
        int d = dire.front();
        radiant.pop();
        dire.pop();
        if (r < d)
            radiant.push(r + senate.size());
        else
            dire.push(d + senate.size());
    }
    return radiant.empty() ? "Dire": "Radiant";
}

int main() {

    std::cout << predictPartyVictory("RDD") << std::endl;
    return 0;
}
