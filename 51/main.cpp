#include <iostream>
#include <vector>
using namespace std;

vector<bool> col, leftDiag, rightDiag;
vector<int> row;
vector<vector<string>> ans;
void dfs(int cur, int& n) {
    if (cur == n) {
        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string s;
            for (int j = 0; j < n; j++) {
                if (j == row[i])
                    s += 'Q';
                else
                    s += '.';
            }
            temp.push_back(s);
        }
        ans.push_back(temp);
    }

    else {
        for (int i = 0; i< n; i++){
            if (col[i] && leftDiag[i-cur+n-1] && rightDiag[i+cur]) {
                col[i] = leftDiag[i - cur + n - 1] = rightDiag[i + cur] = false;
                row[cur] = i;
                dfs(cur + 1, n);
                row[cur] = -1;
                col[i] = leftDiag[i - cur + n - 1] = rightDiag[i + cur] = true;
            }
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    ans.clear();
    row.clear();
    col.clear();
    leftDiag.clear();
    rightDiag.clear();

    row.resize(n, -1);
    col.resize(n, true);
    leftDiag.resize(n * 2 - 1, true);
    rightDiag.resize(n * 2 - 1, true);
    dfs(0, n);

    return ans;
}

int main() {
    solveNQueens(4);

    for (auto& r: ans)
        for (auto& s: r)
            cout << s<<endl;


    return 0;
}