#include <iostream>
#include <vector>
using namespace std;

vector<int> findSquare(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<pair<int, int>>>dp(row, vector<pair<int, int>>(col, make_pair(0, 0)));

    dp[row-1][col-1] = make_pair((matrix[row-1][col-1]+1)%2, (matrix[row-1][col-1]+1)%2);
    for (int i = row - 2; i >= 0; i--) {
        if (matrix[i][col-1])
            dp[i][col - 1] = make_pair(0, 0);
        else {
            dp[i][col - 1].first = 1;
            dp[i][col - 1].second = dp[i+1][col-1].second + 1;
        }
    }

    for (int i = col - 2; i >= 0; i--) {
        if (matrix[row-1][i])
            dp[row-1][i] = make_pair(0, 0);
        else {
            dp[row-1][i].second = 1;
            dp[row-1][i].first = dp[row-1][i+1].first + 1;
        }
    }

    for (int i = row-2; i >= 0; i--) {
        for (int j = col - 2; j >= 0; j--) {
            if (matrix[i][j])
                dp[i][j] = make_pair(0, 0);
            else {
                dp[i][j].first = dp[i][j+1].first + 1;
                dp[i][j].second = dp[i+1][j].second + 1;
            }
        }
    }


    int maxL = 0;
    int x = -1, y = -1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int l = min(dp[i][j].first, dp[i][j].second);

            if (l > 0) {
                int t = min(min(l - 1, col - 1 - j), row - 1 - i);
                while ((dp[i+t][j].first < l || dp[i][j+t].second < l) && l > 0) {
                    l--;
                    t = min(min(l - 1, col - 1 - j), row - 1 - i);
                }
                if (l > maxL) {
                    maxL = l;
                    x = i;
                    y = j;
                }
            }
        }
    }


    if (x < 0 || y < 0)
        return vector<int> {};

    return vector<int>{x, y, maxL};
}

int main() {
    vector<vector<int>>m;
    for (int i = 0; i < 3; i++) {
        vector<int>l;
        m.push_back(l);
        for (int j = 0; j < 3; j++) {
            int a;
            cin >> a;
            m[i].push_back(a);
        }
    }
    vector<int>p = findSquare(m);
    std::cout << p[0] << ' ' << p[1] << p[2] << std::endl;
    return 0;
}
