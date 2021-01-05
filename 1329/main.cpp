#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void sort(vector<vector<int>>& mat, vector<int>& temp, int x, int y) {
    int a = x;
    int b = y;
    while (a < mat.size() && b < mat[0].size()) {
        temp.push_back(mat[a++][b++]);
    }
    std::sort(temp.begin(), temp.end());
    a = x;
    b = y;
    int i = 0;
    while (a < mat.size() && b < mat[0].size()) {
        mat[a++][b++] = temp[i++];
    }
    temp.clear();
}

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    vector<int> temp;
    for (int i = 0; i < mat[0].size(); i++)
        sort(mat, temp, 0, i);
    for (int j = 1; j < mat.size(); j++)
        sort(mat, temp, j, 0);
    return mat;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
