#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    vector<int>task(26);
    for (auto& i: tasks) {
        task[i - 'A']++;
    }
    sort(task.begin(), task.end());
    int maxTime = task[25];
    int gap = (maxTime - 1) * n;
    for (int i = 24; i >= 0; i--)
        gap -= min(maxTime - 1, task[i]);
    return (gap < 0) ? tasks.size(): gap + tasks.size();
}

int main() {
    vector<char> tasks;
    tasks.push_back('A');
    tasks.push_back('A');
    tasks.push_back('A');
    tasks.push_back('B');
    tasks.push_back('B');
    tasks.push_back('B');
cout<<leastInterval(tasks, 2);
    return 0;
}
