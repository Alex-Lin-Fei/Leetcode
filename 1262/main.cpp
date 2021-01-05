#include <iostream>
#include <vector>
using namespace std;

int maxSumDivThree(vector<int>& nums) {
    vector<int>dp(3);
    for (int num : nums) {
        int res = num % 3;

        int d_0 = dp[(3 + 0 - res) % 3];
        int d_1 = dp[(3 + 1 - res) % 3];
        int d_2 = dp[(3 + 2 - res) % 3];

        if (d_0 || res == 0)
            dp[0] = max(dp[0], d_0 + num);
        if (d_1 || res == 1)
            dp[1] = max(dp[1], d_1 + num);
        if (d_2 || res == 2)
            dp[2] = max(dp[2], d_2 + num);
    }
    return dp[0];
}



int main() {
    vector<int>d;
    d.push_back(3);
    d.push_back(6);
    d.push_back(5);
    d.push_back(1);
    d.push_back(8);

    std::cout << maxSumDivThree(d) << std::endl;
    return 0;
}
