#include <iostream>
#include <vector>
using namespace std;

int l, r, u, d;
int sum;
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void dfs(vector<vector<int>>& A, int x, int y) {
    l = (l > y) ? y: l;
    r = (r > y) ? r: y;
    u = (u > x) ? x: u;
    d = (d > x) ? d: x;
    A[x][y] = 0;
    sum++;
    for (auto & i: dir) {
        int a = i[0] + x;
        int b = i[1] + y;
        if (a >= 0 && a < A.size() && b >= 0 && b < A[0].size() && A[a][b])
            dfs(A, a, b);
    }
}

int numEnclaves(vector<vector<int>>& A) {
    int ans = 0;
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < A[0].size(); j++) {
            if (A[i][j] && i > 0 && i < A.size() - 1 && j > 0 && j < A[0].size() - 1) {
                l = r = j;
                u = d = i;
                sum = 0;
                dfs(A, i, j);
                if (l > 0 && r < A[0].size() - 1 && u > 0 && d < A.size() - 1)
                    ans += sum;
            }
        }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
