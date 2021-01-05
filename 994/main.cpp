#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int orangesRotting(vector<vector<int>>& grid) {
    int r = grid.size();
    int c = grid[0].size();
    int step = 0;
    int target=0;
    int sum=0;

    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 1)
                target++;
            if (grid[i][j] == 2)
                q.push(make_pair(i, j));
        }

    while (!q.empty()) {
        int sz = q.size();

        while (sz--) {

            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (auto &d: dir) {
                int a = x + d[0];
                int b = y + d[1];

                if (a < r && a >= 0 && b < c && b >= 0 && grid[a][b] == 1) {
                    sum++;
                    grid[a][b] = 2;
                    q.push(make_pair(a, b));
                }
            }
        }
        if (!q.empty())
            step++;
    }

    return sum == target? step: -1;
}

int main() {


    return 0;
}
