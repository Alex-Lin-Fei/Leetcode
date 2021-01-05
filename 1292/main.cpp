#include <iostream>
#include <vector>
using namespace std;

int maxSideLength(vector<vector<int>>& mat, int threshold) {
    int r = mat.size();
    int c = mat[0].size();
    int ans=0;
    vector<vector<int>> dp(r + 1, vector<int> (c+1));

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }

    int left = 1;
    int right = min(r,c);
    while (left <= right) {
        bool find = false;
        int mid = (left + right)>>1;
        for (int i = mid; i <= r; i++)
            for (int j = mid;!find && j <= c; j++)
                if (dp[i][j] - dp[i-mid][j] - dp[i][j-mid] + dp[i-mid][j-mid] <= threshold) {
                    find  = true;
                    break;
                }
        if (find)
        {
            left = mid+1;
            ans=mid;
        }
        else
            right = mid-1;
    }

    return ans;
}

int main() {
    vector<vector<int>> mat(5, vector<int>(5));
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> mat[i][j];
    cout << maxSideLength(mat, 1);

    return 0;
}
