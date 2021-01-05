#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
//    if (nums.empty())
//        return 0;
//    int start = 0, end = 0;
//    int ans = INT16_MAX;
//    int sum = 0;
//    while (end < nums.size()) {
//        sum += nums[end];
//        while (sum >= s) {
//            ans = min(ans, end - start + 1);
//            sum -= nums[start];
//            start++;
//        }
//        end++;
//    }
//    return (ans == INT16_MAX)? 0: ans;
//    计算前缀和
    vector<int> preSum(nums.size() + 1);
    preSum[0] = 0;
    for (int i = 1; i <= nums.size(); i++)
        preSum[i] = preSum[i - 1] + nums[i - 1];
//    二分查找
    int ans = INT16_MAX;
    for (int i = 1; i <= nums.size(); i++) {
        int target = s + preSum[i - 1];
        auto bound = lower_bound(preSum.begin(), preSum.end(), target);
        if (bound != preSum.end()) {
            ans = min(ans, bound - preSum.begin() - (i - 1));
        }
    }
    return (ans == INT16_MAX) ? 0 : ans;
}

int main() {
    vector<int>nums;
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(10);
    nums.push_back(7);
    nums.push_back(4);
    nums.push_back(9);
    nums.push_back(2);
    nums.push_back(8);

    int s = 15;

    std::cout << minSubArrayLen(s, nums) << std::endl;
    return 0;
}
