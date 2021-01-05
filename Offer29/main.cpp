#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;
void track(vector<vector<int>>& matrix, int a, int b, int c, int d) {
    for (int j = b; j <= d; j++)
        ans.push_back(matrix[a][j]);
    for (int i = a + 1; i <= c; i++)
        ans.push_back(matrix[i][d]);
    if (a < c)
        for (int j = d - 1; j >= a; j--)
            ans.push_back(matrix[c][j]);
    if (b < d)
        for (int i = c - 1; i > a; i--)
            ans.push_back(matrix[i][b]);
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty())
        return ans;
    int a = 0, b = 0, c = matrix.size() - 1, d = matrix[c].size() - 1;
    while (a <= c && b <= d) {
        track(matrix, a, b, c, d);
        a++, b++, c--, d--;
    }
    return ans;
}

int main() {
    vector<vector<int>> m{{1,2,3, 4}, {5,6, 7,8},{9, 10,11,12}};
//vector<vector<int>> m{{1, 5}};
    spiralOrder(m);
    for (auto & i: ans)
        cout << i << ' ';
    return 0;
}
