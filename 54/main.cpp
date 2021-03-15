#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;

    int startR = 0, startC = -1, endR = matrix.size(), endC = matrix[0].size();
    int r = 0, c = -1;

    int cycles = (min(matrix.size(), matrix[0].size()) + 1) / 2;

    while (cycles--) {
        while (c + 1 < endC) {
            c++;
            ans.push_back(matrix[r][c]);
        }

        if (r+1>= endR)
            break;
        while (r + 1 < endR) {
            r++;
            ans.push_back(matrix[r][c]);
        }

        if (c-1<=startC)
            break;
        while (c - 1 > startC) {
            c--;
            ans.push_back(matrix[r][c]);
        }

        while (r - 1 > startR) {
            r--;
            ans.push_back(matrix[r][c]);
        }
        startR++;
        startC++;
        endR--;
        endC--;
    }
    for (auto i: ans) {
        cout << i << ' ';
    }
    return ans;
}

int main() {
    int r = 4, c = 4;
    vector<vector<int>> matrix(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            matrix[i][j] = i * c + j + 1;
        }
    }
    spiralOrder(matrix);

    return 0;
}
