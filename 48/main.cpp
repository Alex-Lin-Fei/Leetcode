#include <iostream>
#include <vector>
using namespace std;

vector<int> temp;
void rotate(vector<vector<int>>& matrix, int layers) {
    if (layers <= 1)
        return;
    else {
        int s = (matrix.size() - layers) >> 1;
        int t = s + layers - 1;
//        旋转边
//        保存上边
        for (int i = s + 1; i < t; i++)
            temp.push_back(matrix[s][i]);
//        left
        for (int i = s + 1; i < t; i++)
            matrix[s][t+s-i] = matrix[i][s];
//        down
        for (int i = s + 1; i < t; i++)
            matrix[i][s] = matrix[t][i];
//        right
        for (int i = s + 1; i < t; i++)
            matrix[t][i] = matrix[t+s-i][t];
//        up
        for (int i = s + 1; i < t; i++)
            matrix[i][t] = temp[i - s - 1];
//        旋转四个角
        temp.clear();
        temp.push_back(matrix[s][s]);
        matrix[s][s] = matrix[t][s];
        matrix[t][s] = matrix[t][t];
        matrix[t][t] = matrix[s][t];
        matrix[s][t] = temp[0];
        temp.clear();
        rotate(matrix, layers-2);
    }
}

void rotate(vector<vector<int>>& matrix) {
    rotate(matrix, matrix.size());
}

int main() {
    vector<vector<int>> matrix = {{1,2,3, 4},
                                  {5,6, 7,8},
                                  {9, 10, 11, 12},
                                  {13, 14, 15, 16}};
    rotate(matrix, 4);
    for (auto & row: matrix) {
        for (auto &i: row)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}
