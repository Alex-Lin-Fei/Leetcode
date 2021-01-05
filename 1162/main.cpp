#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};


int maxDistance(vector<vector<int>>& grid) {
    queue<pair<int, int>>q;

    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            if (grid[i][j] == 1)
                q.push(make_pair(i,j));
            int step = 0;
            while (!q.empty()) {
                int sz = q.size();

                while (sz--) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (auto& d: dir) {
                        int a = d[0] + x;
                        int b = d[1] + y;
                        if (a < grid.size() && a >= 0&& b < grid[0].size()
                        && b >= 0 && grid[a][b] == 0) {
                            grid[a][b] = 1;
                            q.push(make_pair(a,b));
                        }
                    }
                }
                if (!q.empty())
                    step++;
            }
    return step;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
