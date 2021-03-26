#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//int maxSubArray(vector<int>& nums) {
//    int tot = nums[nums.size() - 1];
//    int start = tot;
//    for (int i = nums.size() - 2; i >= 0; i--) {
//        if (start < 0)
//            start = 0;
//        start += nums[i];
//        if (start > tot)
//            tot = start;
//    }
//    return tot;
//}
//
//int maxSubArray(vector<int>& nums) {
//    vector<int>dp(nums.size());
//    dp[0] = nums[0];
//    int maxI = dp[0];
//    for (int i = 1; i < nums.size(); i++) {
//        dp[i] = max(nums[i], nums[i] + dp[i - 1]);
//        maxI = max(maxI, dp[i]);
//    }
//    return maxI;
//}

int trap(vector<int>& height) {
    int bottom = 0;
    int ans = 0;
    stack<int> left;

    for (int i = 0; i < height.size(); i++) {
        if (i > 0 && height[i] > height[i-1]) {
            while (!left.empty()) {
                ans += (i - left.top() - 1) * (min(height[left.top()], height[i]) - bottom);
                bottom = min(height[left.top()], height[i]);
                if (height[left.top()] < height[i])
                    left.pop();
                else
                    break;
            }
        }
        if (i + 1 < height.size()) {
            if (height[i] > height[i + 1])
                left.push(i);
            else if (height[i] < height[i + 1]) {
                bottom = height[i];
            }
        }
    }

    return ans;
}

int main() {
    vector<int> height{4,2,0,3,2,5};
    cout << trap(height);

    return 0;
}
