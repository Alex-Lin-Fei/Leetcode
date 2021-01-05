#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int ans;
vector<vector<bool>> visited;
vector<vector<int>> indeg;
queue<pair<int, int>> q;

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs(vector<vector<int>>& matrix, pair<int, int> s) {
    q.push(s);
    int step = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--){
            int x = q.front().first;
            int y = q.front().second;
            visited[x][y] = true;
            q.pop();
            for (auto& i: dir) {
                int a = x + i[0];
                int b = y + i[1];
                if (a < matrix.size() && a >= 0 &&
                b < matrix[0].size() && b >= 0 && matrix[a][b] > matrix[x][y]) {
                    --indeg[a][b];
                    if (!indeg[a][b]) {
                        q.push(make_pair(a, b));
                    }
                }
            }
        }
        step++;
    }
    cout << step << ' ';
    ans = max(ans, step);
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    visited.resize(matrix.size());
    indeg.resize(matrix.size());
    for (int i = 0; i < matrix.size(); i++) {
        visited[i].resize(matrix[0].size());
        indeg[i].resize(matrix[0].size());
    }


    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            for (auto& d: dir) {

                int a = i + d[0];
                int b = j + d[1];
                if (a < matrix.size() && a >= 0 &&
                    b < matrix[0].size() && b >= 0  && matrix[i][j] > matrix[a][b])
                    indeg[i][j]++;
            }
        }
    }


    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (!visited[i][j] && !indeg[i][j]) {
                bfs(matrix, make_pair(i, j));
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix;
//    for (int i = 0; i < 3; i++) {
//        vector<int>l;
//        matrix.push_back(l);
//        for (int j = 0; j < 3; j++) {
//            int a;
//            cin >> a;
//            matrix[i].push_back(a);
//        }
//    }
    std::cout << longestIncreasingPath(matrix) << std::endl;
    return 0;
}
