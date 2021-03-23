#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> row_sum;
public:
    explicit NumMatrix(vector<vector<int>>& matrix) {
        row_sum.resize(matrix.size(), vector<int>(matrix[0].size()));

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                row_sum[i][j] = j == 0 ? matrix[i][j] : row_sum[i][j - 1] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; i++) {
            cout << row_sum[i][col2] << '-' << (col1 == 0 ? 0 : row_sum[i][col1 - 1]) << " = ";
            cout << row_sum[i][col2] - (col1 == 0 ? 0 : row_sum[i][col1 - 1]) << ' ';
            cout << (row_sum[i][col2] - col1 == 0 ? 0 : row_sum[i][col1 - 1]) << endl;
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main() {
    vector<vector<int>> matrix{
            {3, 0, 1, 4, 2},
            {5, 6, 3, 2, 1},
            {1, 2, 0, 1, 5},
            {4, 1, 0, 1, 7},
            {1, 0, 3, 0, 5}
    };
    NumMatrix numMatrix = NumMatrix(matrix);

    std::cout << numMatrix.sumRegion(2,1,4,3) << std::endl;
    return 0;
}
