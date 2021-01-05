#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void transformRow(vector<int> &R) {
    for (auto &i: R)
        i ^= 1;
}

void transformCol(vector<vector<int>> &A, int c) {
    for (auto &row: A)
        row[c] ^= 1;
}

int count(vector<vector<int>> &A, int c) {
    int ans = 0;
    for (auto &row: A)
        ans += row[c];
    return ans;
}

int VectorToNum(vector<int> &v) {
    int sum = 0;
    for (auto &i: v)
        sum = sum * 2 + i;
    return sum;
}


int matrixScore(vector<vector<int>> &A) {
//    将每一行首元素转为1
    for (auto &row: A)
        if (row[0] == 0)
            transformRow(row);

//    转换每一列使得1的数目>0的数目
    for (int j = 0; j < A[0].size(); j++) {
        if (count(A, j) > A.size() / 2)
            continue;
        else
            transformCol(A, j);
    }
    vector<int> tmp;
    tmp.reserve(A.size());
    for (auto &r: A)
        tmp.emplace_back(VectorToNum(r));
    return accumulate(tmp.begin(), tmp.end(), 0);
}

int main() {
    vector<vector<int>> A{{0, 0, 1, 1},
                          {1, 0, 1, 0},
                          {1, 1, 0, 0}};
    cout <<matrixScore(A);
    return 0;
}
