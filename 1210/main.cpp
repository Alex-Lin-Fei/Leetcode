#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


vector<vector<vector<int>>>visited;

int bfs(vector<vector<int>>& grid) {
    int r = grid.size();
    int c = grid[0].size();
    int step = 0;

    queue<pair<int, int>> q;
    q.push(make_pair(1,0));
    visited[0][1][0] = 1;

    while (!q.empty()) {
        int sz = q.size();

        while (sz--) {
            pair<int, int> temp = q.front();
            q.pop();

            int x = temp.first / c;
            int y = temp.first % c;
            int d = temp.second;

            if (x == r-1 && y == c-1 && d==0)
                return step;

            if (d == 0) {
                if (y + 1 < c && !grid[x][y + 1] && !visited[x][y + 1][0]) {
                    visited[x][y + 1][0] = 1;
                    q.push(make_pair(x * c + y + 1, 0));
                }

                if (x + 1 < r && !grid[x + 1][y - 1] && !grid[x + 1][y]) {
                    if (!visited[x + 1][y - 1][1]) {
                        visited[x + 1][y - 1][1] = 1;
                        q.push(make_pair((x + 1) * c + y - 1, 1));
                    }

                    if (!visited[x + 1][y][0]) {
                        visited[x + 1][y][0] = 1;
                        q.push(make_pair((x + 1) * c + y, 0));
                    }
                }
            } else if (d == 1) {
                if (x + 1 < r && !grid[x + 1][y] && !visited[x + 1][y][1]) {
                    visited[x + 1][y][1] = 1;
                    q.push(make_pair((x + 1) * c + y, 1));
                }

                if (y + 1 < c && !grid[x - 1][y + 1] && !grid[x][y + 1]) {
                    if (!visited[x - 1][y + 1][0]) {
                        visited[x - 1][y + 1][0] = 1;
                        q.push(make_pair((x - 1) * c + y + 1, 0));
                    }

                    if (!visited[x][y + 1][1]) {
                        visited[x][y + 1][1] = 1;
                        q.push(make_pair(x * c + y + 1, 1));
                    }
                }
            }

        }
        step++;
    }

    return -1;
}

int minimumMoves(vector<vector<int>>& grid) {
    int r = grid.size();
    for (int i = 0; i < r; i++)
        visited.push_back(vector<vector<int>>(r, vector<int>(2)));
    return bfs(grid);
}



//#define RIGHT 0
//#define DOWN 1
//typedef pair<int,int> pii;
//
//
//int minimumMoves(vector<vector<int>>& grid) {
//    int r = grid.size();
//    int c = grid[0].size();
//    int step = 0;
//    queue<pii> qu;
//    int dp[100][100][2];
//
//
//    memset(dp, 0, sizeof(dp));
//    dp[0][1][RIGHT] = 1;
//    qu.push(make_pair(1, RIGHT));
//
//    while (!qu.empty()) {
//        int sz = qu.size();
//
//        for (int i = 0; i < sz; ++i) {
//            pii curr = qu.front();
//            qu.pop();
//            int x = curr.first / c;
//            int y = curr.first % c;
//            int d = curr.second;
//
//            if (x == r - 1 && y == c - 1 && d == RIGHT) {
//                return step;
//            }
//
//            if (d == RIGHT) {
//                if (y < c - 1 && grid[x][y + 1] != 1) {
//                    if (!dp[x][y + 1][RIGHT]) {
//                        dp[x][y + 1][RIGHT] = 1;
//                        qu.push(make_pair(x * c + y + 1, RIGHT));
//                    }
//                }
//                if (x < r - 1 && grid[x + 1][y - 1] == 0 && grid[x + 1][y] == 0) {
//                    if (!dp[x + 1][y][RIGHT]) {
//                        dp[x + 1][y][RIGHT] = 1;
//                        qu.push(make_pair((x + 1) * c + y, RIGHT));
//                    }
//                    if (!dp[x + 1][y - 1][DOWN]) {
//                        dp[x + 1][y - 1][DOWN] = 1;
//                        qu.push(make_pair((x + 1) * c + y - 1, DOWN));
//                    }
//                }
//            } else if (d == DOWN) {
//
//                if (x < r - 1 && grid[x + 1][y] != 1) {
//                    if (!dp[x + 1][y][DOWN]) {
//                        dp[x + 1][y][DOWN] = 1;
//                        qu.push(make_pair((x + 1) * c + y, DOWN));
//                    }
//                }
//                if (y < c - 1 && grid[x - 1][y + 1] == 0 && grid[x][y + 1] == 0) {
//                    if (!dp[x][y + 1][DOWN]) {
//                        dp[x][y + 1][DOWN] = 1;
//                        qu.push(make_pair(x * c + y + 1, DOWN));
//                    }
//                    if (!dp[x - 1][y + 1][RIGHT]) {
//                        dp[x - 1][y + 1][RIGHT] = 1;
//                        qu.push(make_pair((x - 1) * c + y + 1, RIGHT));
//                    }
//                }
//            }
//        }
//        step++;
//    }
//
//    return -1;
//}

int main() {
    int n = 6;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    std::cout << minimumMoves(grid) << std::endl;
    return 0;
}
