#include <iostream>
#include <vector>
using namespace std;

int largest1BorderedSquare(vector<vector<int>>& grid) {
    vector<vector<int>> dp_left(grid.size(), vector<int>(grid[0].size(), 0));
    vector<vector<int>> dp_up(grid.size(), vector<int>(grid[0].size(), 0));
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (!grid[i][j]) {
                dp_left[i][j] = dp_up[i][j] = 0;
            }
            else {
                dp_left[i][j] = (j == 0)? 1: dp_left[i][j - 1] + 1;
                dp_up[i][j] = (i == 0)? 1: dp_up[i - 1][j] + 1;
            }

        }
    }

    int maxLen = 0;
    for (int i = grid.size() - 1; i >= 0; i--) {
        for (int j = grid[0].size() - 1; j >= 0; j--)
        if (grid[i][j]){
            int len = min(dp_left[i][j], dp_up[i][j]);
            while (dp_left[i - len + 1][j] < len || dp_up[i][j - len + 1] < len)
                len--;
            maxLen = max(maxLen, len);
        }
    }
    return maxLen * maxLen;
}

int main() {
    vector<vector<int>>grid;
    int x = 3;
    int y = 3;
    for (int i = 0; i < x; i++) {
        vector<int>line;
        grid.push_back(line);
        for (int j = 0; j < y; j++) {
            int n;
            cin >> n;
            grid[i].push_back(n);
        }
    }
    cout << largest1BorderedSquare(grid);


    return 0;
}
