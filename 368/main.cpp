#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    vector<int>dp(nums.size(), 1);
    vector<int>pre(nums.size(), -1);
    sort(nums.begin(), nums.end());
    int maxl = 0;
    int maxI = -1;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
        }
        if (maxl < dp[i]) {
            maxl = dp[i];
            maxI = i;
        }
    }
    vector<int>res;
    while (maxI != -1) {
        res.push_back(nums[maxI]);
        cout << nums[maxI] << ' ';
        maxI = pre[maxI];
    }

    return res;
}

int main() {
    vector<int>nums;
    int x = 1;
    while (x--) {
        int a = rand()%10+1;
        cout << a << ' ';
        nums.push_back(a);
    }
    cout << endl;
    largestDivisibleSubset(nums);

    return 0;
}
