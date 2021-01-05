#include <iostream>
#include <vector>
using namespace std;

int find(int s, int e, vector<int>& A, int diff) {
    while (s < e) {
        int m = (s + e) / 2;
        if (A[m] < diff)
            s = m + 1;
        else if (A[m] > diff)
            e = m;
        else
            return m;
    }
    return -1;
}

int lenLongestFibSubseq(vector<int>& A) {
    vector<vector<int>>dp(A.size(), vector<int>(A.size()));
    int maxL = 0;
    for (int i = 0; i < A.size(); i++) {
        for (int j = i + 1; j < A.size(); j++) {
            int k = find(j, A.size(), A, A[i] + A[j]);
            if (k != -1) {
                dp[j][k] = max(dp[j][k], dp[i][j] + 1);
                maxL = max(maxL, dp[j][k]);
            }
        }
    }
    return (maxL == 0)? 0: maxL + 2;
}

int main() {
    vector<int> n;
    n.push_back(1);
//    n.push_back(2);
    n.push_back(3);
    n.push_back(7);
    n.push_back(11);
    n.push_back(12);
    n.push_back(14);
    n.push_back(18);

    std::cout << lenLongestFibSubseq(n) << std::endl;
    return 0;
}
