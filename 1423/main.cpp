#include <iostream>
#include <vector>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int len = cardPoints.size() - k;
    vector<int>dp(k + 1, 0);
    for (int i = 0; i < len; i++)
        dp[0] += cardPoints[i];
    int minS = dp[0];
    for (int i = 1; i <= k; i++) {
        dp[i] = dp[i - 1] - cardPoints[i - 1] + cardPoints[i + len - 1];
        minS = min(minS, dp[i]);
    }
    for (auto& i: dp)
        cout << i << ' ';
    cout << endl;
    int sum = 0;
    for (auto & i: cardPoints)
        sum += i;
    return sum - minS;
}


int main() {
    vector<int>c;
    c.push_back(1);
    c.push_back(79);
    c.push_back(80);
    c.push_back(1);
    c.push_back(1);
    c.push_back(1);
    c.push_back(200);
    c.push_back(1);
//    c.push_back(6);
//    c.push_back(1);


    std::cout << maxScore(c, 3) << std::endl;
    return 0;
}
