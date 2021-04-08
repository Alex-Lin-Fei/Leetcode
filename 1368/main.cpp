#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<pair<int, int>> direct{{0,0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int minCost(vector<vector<int>>& grid) {
    int r = grid.size(), c = grid[0].size();

//    <dist, pos>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> que;
    vector<int> dist(r * c, INT32_MAX);
    vector<int> visited(r * c);
    dist[0] = 0;

    que.push({0, 0});
    while (!que.empty()) {
        auto item = que.top();
        int dis = item.first;
        int pos = item.second;
        que.pop();

        if (visited[pos])
            continue;

        visited[pos] = true;
        int x = pos / c;
        int y = pos % c;
        for (int i = 1; i <= 4; i++) {
            int a = x + direct[i].first;
            int b = y + direct[i].second;
            int cos = dis + (grid[x][y] == i? 0: 1);

            if (a >= 0 && a < r && b >= 0 && b < c && cos < dist[a*c+b]) {
                dist[a*c+b] = cos;
                que.push({cos, a*c+b});
            }
        }
    }

    for (int i = 0; i < dist.size(); i++) {
        cout << dist[i] << ' ';
        if (i % c == 0)
            cout << endl;
    }

    return dist[r*c-1];
}

int main() {
    vector<vector<int>> grid {{1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}};
    cout << minCost(grid);

    return 0;
}
