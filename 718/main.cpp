#include <iostream>
#include <vector>
using namespace std;

int findLength(vector<int>& A, vector<int>& B) {
    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1));
    for (int i = 0; i < dp.size(); i++)
        dp[i][0] = 0;
    for (int i = 0; i < dp[0].size(); i++)
        dp[0][i] = 0;


    int maxL = INT16_MIN;
    for (int i = 1; i <= A.size(); i++) {
        for (int j = 1; j <= B.size(); j++) {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = 0;
            maxL = max(maxL, dp[i][j]);
        }
    }
    return maxL;
}


int main() {
    vector<int>A;
    A.push_back(0);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    vector<int>B;
    B.push_back(1);
    B.push_back(0);
    B.push_back(1);
    B.push_back(0);
    B.push_back(1);



    std::cout << findLength(A, B) << std::endl;
    return 0;
}
