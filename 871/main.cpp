#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int totalFuel = startFuel;
    int times = 0;

    priority_queue<int> priorityQueue;
    stations.push_back({target, 0});


    for (auto &station : stations) {
        while (totalFuel < station[0]) {
            if (priorityQueue.empty())
                return -1;
            else {
                totalFuel += priorityQueue.top();
                priorityQueue.pop();
                times++;
            }
        }
        priorityQueue.push(station[1]);
    }

    return times;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
