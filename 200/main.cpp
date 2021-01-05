#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<char>> grid;
queue<pair<int, int>> q;

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void bfs(vector<vector<char>> & grid, int x, int y) {
    q.push(make_pair(x, y));
    grid[x][y]= '0';

    while (!q.empty()) {
        pair<int, int> temp = q.front();
        q.pop();
        for (auto & i : dir) {
            int a = temp.first + i[0];
            int b = temp.second + i[1];
            if (a >= 0 && a < grid.size() && b >= 0
            && b < grid[0].size() && grid[a][b] == '1') {
                grid[a][b] = '0';
                q.push(make_pair(a, b));
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int ans = 0;
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '1') {
                bfs(grid, i, j);
                ans++;
            }
        }
    return ans;
}

int main() {
    for (int i = 0; i < 2; i++) {
        vector<char> line;
        grid.push_back(line);
        for (int j = 0; j < 2; j++) {
            int n;
            cin >> n;
            if (n == 0)
                grid[i].push_back('0');
            else
                grid[i].push_back('1');
        }
    }
    cout <<  '*';
    cout << numIslands(grid);


    return 0;
}
