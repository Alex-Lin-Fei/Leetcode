#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isValid(pair<int, int> x, vector<vector<int>>& grid) {
    return x.first >= 0 && x.first < grid.size() && x.second < grid[0].size()
    && x.second >=0 && grid[x.first][x.second] == 0;
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if (grid[0][0] || grid[grid.size()-1][grid[0].size()-1])
        return -1;
    queue<pair<int, int>> que;
    int steps = 1;

    que.push(make_pair(0, 0));
    grid[0][0] = 1;
    while (!que.empty()) {
        int size = que.size();
        while (size--) {
            pair<int, int> temp = que.front();
            que.pop();
            if (temp == pair<int, int>(grid.size() - 1, grid[0].size() - 1))
                return steps;
            for (int i = -1; i <= 1; i++)
                for (int j = -1; j <= 1; j++) {
                    if (i != 0 || j != 0) {
                        int x = temp.first + i;
                        int y = temp.second + j;

                        if (isValid(make_pair(x, y), grid)) {
                            grid[x][y] = 1;
                            que.push(make_pair(x, y));
                        }
                    }
                }
        }
        steps++;
    }
    return -1;
}

int main() {
    vector<vector<int>> v = {{0,0,0}, {1,1,0}, {1,1,0}};
    std::cout << shortestPathBinaryMatrix(v) << std::endl;
    for(auto& row: v) {
        for (auto &i: row)
            cout << i <<' ';
        cout << endl;
    }
    return 0;
}
