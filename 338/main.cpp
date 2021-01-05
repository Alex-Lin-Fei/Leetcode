#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int num) {
    vector<int>dp(num + 1);
    dp[0] = 0;
    int temp = 1;
    while (temp <= num) {
        for (int i = temp; i < min(temp * 2, num + 1); i++) {
            dp[i] = dp[i - temp] + 1;
        }
        temp *= 2;
    }

    return dp;
}

int main() {
    countBits(16);
    return 0;
}
