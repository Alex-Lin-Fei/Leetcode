#include <iostream>
#include <vector>
#include <set>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    set<int> rows, cols;

    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[0].size(); j++)
            if (!matrix[i][j])
            {
                rows.insert(i);
                cols.insert(j);
            }

    for (auto & row: rows) {
        for (int j = 0; j < matrix[row].size(); j++)
            matrix[row][j] = 0;
    }

    for (auto & col: cols) {
        for (int i = 0; i < matrix.size(); i++)
            matrix[i][col] = 0;
    }
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
