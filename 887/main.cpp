#include <iostream>
#include <vector>
using namespace std;


int Dp(vector<vector<int>> & dp, int k, int n) {
    if (k == 1) {
        return n;
    }
    if (!n)
        return 0;
    if (dp[k][n] < INT16_MAX)
        return dp[k][n];
    int ans = INT16_MAX;
    int low = 1;
    int  high = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        int broken = Dp(dp, k - 1, mid - 1);
        int not_broken = Dp(dp, k, n - mid);
        if (broken > not_broken) {
            high = mid - 1;
            ans = min(ans, broken + 1);
        }
        else {
            low = mid + 1;
            ans = min(ans, not_broken + 1);
        }
    }
    dp[k][n] = ans;
    return ans;
}

int superEggDrop(int K, int N) {
    vector<vector<int>> dp = vector<vector<int>>(K + 1, vector<int>(N + 1, INT16_MAX));
    return Dp(dp, K, N);
}


int main() {
    cout << superEggDrop(1, 2);
    return 0;
}
