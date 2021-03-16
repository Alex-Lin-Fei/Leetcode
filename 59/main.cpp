#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    int now = 1;

    int startR = 0, startC = -1, endR = n, endC = n;
    int r = 0, c = -1;

    int cycles = (n + 1) / 2;

    while (cycles--) {
        while (c + 1 < endC) {
            c++;
            matrix[r][c] = now++;
        }

        if (r+1>= endR)
            break;
        while (r + 1 < endR) {
            r++;
            matrix[r][c] = now++;
        }

        if (c-1<=startC)
            break;
        while (c - 1 > startC) {
            c--;
            matrix[r][c] = now++;
        }

        while (r - 1 > startR) {
            r--;
            matrix[r][c] = now++;
        }
        startR++;
        startC++;
        endR--;
        endC--;
    }

    for (auto row: matrix) {
        for (auto i : row)
            cout << i << ' ';
        cout << endl;
    }

    return matrix;
}

int main() {
    generateMatrix(4);

    return 0;
}
