#include <iostream>
#include <vector>
using namespace std;

int surfaceArea(vector<vector<int>>& grid) {
    int ans = 0;

    for (auto &row: grid)
        for (auto &h: row)
            ans += 2 + h * 4;

    for (int i = 0; i < grid.size() - 1; i++) {
        for (int j = 0; j < grid[i].size() - 1; j++) {
//            减去左边的重叠部分
            ans -= 2 * min(grid[i][j], grid[i][j + 1]);
//            减去下方的重叠部分
            ans -= 2 * min(grid[i][j], grid[i + 1][j]);
        }
    }

    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
