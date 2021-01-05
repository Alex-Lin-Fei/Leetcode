#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> G;
vector<bool> visited;


bool bfs(int s, int t) {
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
        int temp = que.front();
        que.pop();

        for (auto& node: G[temp]) {
            if (visited[node])
                continue;
            if (node == t)
                return true;
            else {
                que.push(node);
                visited[node] = true;
            }
        }
    }
    return false;
}

bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
    G.clear();
    visited.clear();
    visited.resize(n, false);
    G.resize(n);
    for (auto &g: G)
        g.clear();

//    加边
    for (auto &edge: graph) {
//       剔除自环和平行边

        if (edge[0] == edge[1] && count(G[edge[0]].begin(), G[edge[0]].end(), edge[1]))
            continue;
        else
            G[edge[0]].push_back(edge[1]);

    }
    return bfs(start, target);
}

int main() {
    vector<vector<int>> G = {{0,1}, {1, 2}, {1, 3}, {1, 10}, {1, 11}, {1, 4},
                             {2, 4}, {2, 6}, {2, 9}, {2, 10}, {2, 4}, {2, 5}, {2, 10},
                             {3, 7}, {3, 7}, {4, 5}, {4, 11}, {4, 11}, {4, 10}, {5, 7},
                             {5, 10}, {6, 8}, {7, 11}, {8, 10}};
    cout << findWhetherExistsPath(12, G, 2, 3);
    return 0;
}
