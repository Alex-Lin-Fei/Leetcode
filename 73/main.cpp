#include <iostream>
#include <set>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    set<int>col, row;
    for (auto i = 0; i < matrix.size(); i++)
        for (auto j = 0; j < matrix[0].size(); j++) {
            if (!matrix[i][j]) {
                row.insert(i);
                col.insert(j);
            }
        }
    for (auto i = 0; i < matrix.size(); i++)
        for (auto j = 0; j < matrix[0].size(); j++) {
            if (row.count(i) || col.count(j)) {
                matrix[i][j] = 0;
            }
        }

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
