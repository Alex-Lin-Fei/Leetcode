#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

//DFS overtime
/*
void dfs(vector<vector<int>> &grid, int x, int y, int steps, int &k, int rem_k, int &ans, vector<vector<int>> &visited) {
//    判断是否在grid范围内
    if (!(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) || visited[x][y])
        return;

//    判断是否可以走

    if (grid[x][y]) {
        if (rem_k > 0)
            rem_k--;
        else {
            return;
        }
    }

    if (steps > ans)
        return;

    visited[x][y] = 1;

//到达终点
    if (x == grid.size() - 1 && y == grid[0].size() - 1) {
        ans = min(ans, steps);
    }

    dfs(grid, x, y + 1, steps + 1, k, rem_k, ans, visited);
    dfs(grid, x, y - 1, steps + 1, k, rem_k, ans, visited);
    dfs(grid, x - 1, y, steps + 1, k, rem_k, ans, visited);
    dfs(grid, x + 1, y, steps + 1, k, rem_k, ans, visited);

    visited[x][y] = 0;
}

int shortestPath(vector<vector<int>> &grid, int k) {
    int ans = INT32_MAX;
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));
    dfs(grid, 0, 0, 0, k, k, ans, visited);

    return ans < INT32_MAX ? ans : -1;
}
*/

struct Node {
    int x, y, res;
    Node(int x_ , int y_ ,int res_): x{x_}, y{y_}, res{res_} {}
};


vector<int> dir{0,1,0,-1,0};

int shortestPath(vector<vector<int>> & grid, int k) {
    queue<Node> que;
    bool visited[grid.size()][grid[0].size()][k+1];
    memset(visited, false, sizeof(visited));
    que.push(Node(0, 0, k));
    visited[0][0][k] = true;

    for (int step = 1;!que.empty(); step++) {
        int size = que.size();

        while (size--) {
            Node now= que.front();
            que.pop();

            for (int i = 0; i < 4; i++) {
                int x = now.x + dir[i];
                int y = now.y + dir[i+1];
                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
                    if (!grid[x][y] && !visited[x][y][now.res]) {
                        if (x == grid.size() - 1 && y == grid[0].size() - 1)
                            return step;
                    } else if (grid[x][y] && !visited[x][y][now.res-1]){
                        if (x == grid.size() - 1 && y == grid[0].size() - 1)
                            return step;
                        now.res--;
                    }
                    que.push(Node(x, y, now.res));
                    visited[x][y][now.res] = true;
                }
            }
        }
    }

    return -1;
}

int main() {
vector<vector<int>> grid;
    vector<vector<int>> g{
                { 0, 1, 0 },
                { 0, 1, 0 },
                { 0, 0, 0 }
            };
            cout << shortestPath(grid, 1);

            return 0;
         }
