#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//int dir[2][2] = {{0, 1}, {1, 0}};

//bool valid(vector<vector<int>>& obstacleGrid, int x, int y) {
//    return x >= 0 && x < obstacleGrid.size() && y >= 0 && y < obstacleGrid[0].size();
//}

//vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
//    vector<vector<int>> res;
//    if (obstacleGrid[0][0] == 1 || obstacleGrid[obstacleGrid.size()
//     - 1][obstacleGrid[0].size() - 1] == 1)
//        return res;
//    int flag = 2;
//    queue<pair<int, int>> q;
//    q.push(make_pair(0, 0));
//    bool l = false;
//    while (!q.empty()) {
//        int n = q.size();
//        while (n--) {
//            pair<int, int> temp = q.front();
//            if (temp.first == obstacleGrid.size() - 1 && temp.second == obstacleGrid[0].size() - 1) {
//                l = true;
//                break;
//            }
//            q.pop();
//            for (auto &i: dir) {
//                int x = temp.first + i[0];
//                int y = temp.second + i[1];
//                if (valid(obstacleGrid, x, y) && !obstacleGrid[x][y]) {
//                    obstacleGrid[x][y] = flag;
//                    q.push(make_pair(x, y));
//                }
//            }
//        }
//        if (l)
//            break;
//
//        flag++;
//    }
//    for (int i = 0; i < obstacleGrid.size(); i++) {
//        for (int j = 0; j < obstacleGrid[0].size(); j++) {
//            cout<< obstacleGrid[i][j] << ' ';
//        }
//        cout << endl;
//    }
//    if (q.empty())
//        return res;
//    flag -= 2;
//    vector<int>here = {static_cast<int>(obstacleGrid.size() - 1), static_cast<int>(obstacleGrid[0].size() - 1)};
//    while (flag > 1) {
//        res.push_back(here);
//        for (auto& i: dir) {
//            int a = here[0] - i[0];
//            int b = here[1] - i[1];
//            if (valid(obstacleGrid, a, b) && obstacleGrid[a][b] == flag) {
//                here = vector<int>{a, b};
//                break;
//            }
//        }
//        flag--;
//    }
//    res.push_back(here);
//    if (here[0] !=0 || here[1]!= 0)
//        res.push_back(vector<int>{0, 0});
//    reverse(res.begin(), res.end());
//    for (int i = 0; i < res.size(); i++) {
//        for (int j = 0; j < res[0].size(); j++) {
//            cout<< res[i][j] << ' ';
//        }
//        cout << endl;
//    }
//
//    return res;
//}

vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();
    vector<vector<int>> res;
//    判断网格是否为空或者起点终点可达
    if (!row || !col || obstacleGrid[0][0] == 1 || obstacleGrid[row - 1][col - 1] == 1)
        return res;

    vector<vector<int>> dp(row, vector<int>(col));
//    处理边界情况
    dp[0][0] = 1;
    for (int i = 1; i < row; i++) {
        if (obstacleGrid[i][0])
            dp[i][0] = 0;
        else
            dp[i][0] = dp[i - 1][0];
    }
    for (int j = 1; j < col; j++) {
        if (obstacleGrid[0][j])
            dp[0][j] = 1;
        else
            dp[0][j] = dp[0][j - 1];
    }
    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (!obstacleGrid[i][j])
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            else
                dp[i][j] = 0;
        }
    }

    if (!dp[row - 1][col - 1])
        return res;
    int r = row - 1, l = col - 1;

    while (r != 0 || l != 0) {
        res.push_back(vector<int>{r, l});
        int up = 0;
        if (r > 0) up = dp[r - 1][l];

        int left = 0;
        if (l > 0) left = dp[r][l - 1];

        if (up >= left) r--;
        else l--;
    }
    res.push_back(vector<int>{0, 0});
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout<< res[i][j] << ' ';
        }
        cout << endl;
    }
    return res;
}


int main() {
    vector<vector<int>> o;
    for (int i = 0; i < 3; i++) {
        vector<int>l;
        o.push_back(l);
        for (int j = 0; j < 2;j++) {
            int a;
            cin >> a;
            o[i].push_back(a);
        }
    }
    pathWithObstacles(o);
    return 0;
}
