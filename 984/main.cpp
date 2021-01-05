#include <iostream>
#include <vector>
using namespace std;

int ans, step;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(int now, int t, vector<vector<int>>& grid, int steps) {
    if (now == t) {
        if (steps == step)
            ans++;
        return;
    }
    else {
        int x = now / grid[0].size();
        int y = now % grid[0].size();
//        cout << "(" << x <<',' <<y<<")"<<endl;

        int temp = grid[x][y];
        grid[x][y] = -1;
//        下一步
        for (auto &d: dir) {
            int a = x + d[0];
            int b = y + d[1];
            if (a >= 0 && a < grid.size() && b >= 0 && b < grid[0].size()
                && grid[a][b] % 2 == 0)
                dfs(a * grid[0].size() + b, t, grid, steps+1);
        }
        grid[x][y] = temp;
    }
}

int uniquePathsIII(vector<vector<int>>& grid) {
    ans = 0;
    int s = 0;
    int t = 0;

    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                s = i * grid[0].size() + j;
            } else if (grid[i][j] == 2) {
                t = i * grid[0].size() + j;
                step++;
            } else if (grid[i][j] == 0)
                step++;
        }
    cout << s << ' ' << t << ' ' << step << endl;
    dfs(s, t, grid, 0);
    return ans;
}

int main() {
    vector<vector<int>> grid={{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
//vector<vector<int>> grid={{0,1},{2,0}};
    cout << uniquePathsIII(grid)<<endl;
    for (auto& row: grid) {
        for (auto &i: row)
            cout << i <<' ';
        cout << endl;
    }

    return 0;
}
