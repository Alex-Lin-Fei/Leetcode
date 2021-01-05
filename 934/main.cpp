#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int shortestBridge(vector<vector<int>>& A) {
    queue<pair<int, int>> q;

    for (int i = 0; i < A[0].size() * A.size(); i++) {
        int x = i / A[0].size();
        int y = i % A[0].size();
        if (A[x][y] == 1) {
            A[x][y] = 2;
            q.push(make_pair(x, y));
            break;
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (auto &d: dir) {
            int a = x + d[0];
            int b = y + d[1];

            if (a < A.size() && a >= 0 && b < A[0].size()
                && b >= 0 && A[a][b] == 1) {
                A[a][b] = 2;
                q.push(make_pair(a, b));
            }
        }
    }

    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < A[0].size(); j++)
            if (A[i][j] == 1)
                q.push(make_pair(i, j));

    int step = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();


            for (auto &d: dir) {
                int a = x + d[0];
                int b = y + d[1];

                if (a < A.size() && a >= 0 && b < A[0].size()
                    && b >= 0) {
                    if (A[a][b] == 0) {
                        A[a][b] = 1;
                        q.push(make_pair(a, b));
                    }
                    if (A[a][b] == 2)
                        return step;
                }
            }
        }
        step++;
    }
    return -1;
}
int f(int x) {
    return (4 * x * x + 8 * x + 6) %11;
}

int main() {
    cout << (12*77+59) % 1001;
    return 0;
}
