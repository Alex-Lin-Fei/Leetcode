#include <iostream>
#include <vector>
#include <set>
using namespace std;

//超时
//int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
//    vector<vector<pair<int, int>>>dp(N, vector<pair<int, int>>(N, make_pair(-1, -1)));
//    int maxl = -1;
//    for (auto &i: mines) {
//        dp[i[0]][i[1]] = make_pair(0, 0);
//    }
//    if (dp[dp.size()-1][dp[0].size()-1].first != 0)
//        dp[dp.size()-1][dp[0].size()-1] = make_pair(1,1);
//
//
//
//    for (int i = dp.size() - 2; i >= 0; i--) {
//        if (dp[i][dp[0].size() - 1] != make_pair(0, 0)) {
//            dp[i][dp[0].size() - 1] = make_pair(1, dp[i+1][dp[0].size() - 1].second + 1);
//        }
//    }
//
//    for (int i = dp[0].size() - 2; i >= 0; i--) {
//        if (dp[dp.size() - 1][i] != make_pair(0, 0)) {
//            dp[dp.size() - 1][i] = make_pair(dp[dp.size() - 1][i+1].first + 1, 1);
//        }
//    }
//
//    for (int i = dp.size() - 2; i >= 0; i--){
//        for (int j = dp[0].size() - 2; j >= 0; j--) {
//            if (dp[i][j]!=make_pair(0, 0)) {
//                dp[i][j] = make_pair(dp[i][j+1].first + 1, dp[i+1][j].second+1);
//            }
//        }
//    }
//
//
//    for (int i = 0; i < dp.size(); i++)
//        for (int j = 0; j < dp[0].size(); j++) {
//            int l = min(dp[i][j].first, dp[i][j].second);
//            int t = 0;
//            if (l > 0) {
//                t = min(l - 1, min(i, j));
//                while (dp[i][j-t].first < 2*t+1 || dp[i-t][j].second < 2*t+1) {
//                    l--;
//                    t = min(l - 1, min(i, j));
//                }
//                maxl = max(maxl, t);
//            }
//        }
//    return maxl+1;
//}

int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
    vector<vector<int>>dp(N, vector<int>(N));
    int count;
    set<int>s;
    int ans = 0;
    for (auto& i: mines)
        s.insert(N * i[0] + i[1]);
    for (int i = 0; i < N; i++) {
        count = 0;
        for (int j = 0; j < N; j++) {
            count = (s.count(N * i + j))? 0: count+1;
            dp[i][j] = count;
        }
        count = 0;
        for (int j = N-1; j >= 0; j--) {
            count = (s.count(N * i + j))? 0: count+1;
            dp[i][j] = min(count, dp[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        count = 0;
        for (int j = 0; j < N; j++) {
            count = (s.count(N * j + i))? 0: count+1;
            dp[j][i] = min(count, dp[j][i]);
        }
        count = 0;
        for (int j = N-1; j >= 0; j--) {
            count = (s.count(N * j + i))? 0: count+1;
            dp[j][i] = min(count, dp[j][i]);
            ans = max(ans, dp[j][i]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    return ans;
}

int main() {
    vector<vector<int>>m;
    for (int i = 0; i < 1; i++) {
        vector<int>l;
        m.push_back(l);
        for (int j = 0; j < 2; j++) {
            int t;
            cin >> t;
            m[i].push_back(t);
        }
    }

    std::cout << orderOfLargestPlusSign(5, m) << std::endl;
    return 0;
}
