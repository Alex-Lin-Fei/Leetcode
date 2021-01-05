#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

vector<int> dir{1, 0, -1, 0, 1};

bool can(int & a, int & b, int & k) {
    return a / 10 + a % 10 + b / 10 + b % 10 <= k;
}

int movingCount(int m, int n, int k) {
    queue<pair<int, int>> que;
    set<pair<int, int>> visited;
    que.push({0, 0});
    visited.insert({0, 0});

    while (!que.empty()) {
        auto now = que.front();
        que.pop();

        for (int i = 0; i < 4; i++) {
            int a = now.first + dir[i];
            int b = now.second + dir[i + 1];
            if (a >= 0 && a < m && b >= 0 && b < n
                && !visited.count({a, b}) && can(a, b, k)) {
                visited.insert({a, b});
                que.push({a, b});
            }
        }
    }
    return visited.size();
}

int main() {
    std::cout << movingCount(3,1,0) << std::endl;
    return 0;
}
