#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> grid;
const int N = 1000;
bool flag = false;

bool dfs(vector<vector<int>>& grid, int x, int y, int front) {

    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
        return false;


    if (front == 1) {
        if (grid[x][y] == 1)
            return (x == grid.size() - 1 && y == grid[0].size() - 1) || dfs(grid, x, y+1, 1);
        else if (grid[x][y] == 3)
            return (x == grid.size() - 1 && y == grid[0].size() - 1) || dfs(grid, x+1, y, 4);
        else if (grid[x][y] == 5)
            return (x == grid.size() - 1 && y == grid[0].size() - 1) || dfs(grid, x-1, y, 2);
        else
            return false;
    }
    else if (front == 2) {
        if (grid[x][y] == 2)
            return (x == grid.size() - 1 && y == grid[0].size() - 1) || dfs(grid, x-1, y,2);
        else if (grid[x][y] == 3)
            return (x == grid.size() - 1 && y == grid[0].size() - 1) || dfs(grid, x, y-1, 3);
        else if (grid[x][y] == 4)
            return (x == grid.size() - 1 && y == grid[0].size() - 1) || dfs(grid, x, y+1, 1);
        else
            return false;
    }

    else if (front == 3) {
        if (grid[x][y] == 1)
            return (x == grid.size() - 1 && y == grid[0].size() - 1) || dfs(grid, x, y-1,3);
        else if (grid[x][y] == 4)
            return (x == grid.size() - 1 && y == grid[0].size() - 1) || dfs(grid, x+1, y, 4);
        else if (grid[x][y] == 6)
            return (x == grid.size() - 1 && y == grid[0].size() - 1) || dfs(grid, x-1, y, 2);
        else
            return false;
    }
    else {
        if (grid[x][y] == 2)
            return (x == grid.size() - 1 && y == grid[0].size() - 1) || dfs(grid, x + 1, y, 4);
        else if (grid[x][y] == 5)
            return (x == grid.size() - 1 && y == grid[0].size() - 1) || dfs(grid, x, y - 1, 3);
        else if (grid[x][y] == 6)
            return (x == grid.size() - 1 && y == grid[0].size() - 1) || dfs(grid, x, y + 1, 1);
        else
            return false;
    }
}

bool hasValidPath(vector<vector<int>>& grid) {
    if (grid.size() == 0)
        return false;
    if (grid[0][0] == 1 || grid[0][0] == 3)
        return dfs(grid, 0, 0, 1);
    else if (grid[0][0] == 4)
        return (dfs(grid, 0, 0, 2) || dfs(grid, 0, 0, 3));
    else
        return dfs(grid, 0, 0, 4);
}


int main() {
    for (int i = 0; i < 1; i++) {
        vector<int> line;
        grid.push_back(line);
        for (int j = 0; j < 3; j++) {
            int n;
            cin >> n;
            grid[i].push_back(n);
        }
    }
    cout << hasValidPath(grid);


    return 0;
}
