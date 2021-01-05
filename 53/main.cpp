#include <iostream>
#include <vector>
using namespace std;

int INF = 0x999999;
int maxCrossSubArray(vector<int> & nums, int low, int high) {
    int leftSum = -INF;
    int sum = 0;
    int mid = (low + high) / 2;
    for (int i = mid; i >= low; i--) {
        sum += nums[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }
    int rightSum = 0;
    sum = 0;
    for (int j = mid + 1; j <= high; j++) {
        sum += nums[j];
        if (sum > rightSum)
            rightSum = sum;
    }
    return rightSum + leftSum;
}

int maxSubArray(vector<int> & nums, int low, int high) {
    if (high == low)
        return nums[high];
    else {
        int leftSum = maxSubArray(nums, low, (low + high) / 2);
        int rightSum = maxSubArray(nums, (low + high) / 2 + 1, high);
        int midSum = maxCrossSubArray(nums, low, high);
        return max(max(leftSum, rightSum), midSum);
    }
}

int maxSubArray(vector<int>& nums) {
//    return maxSubArray(nums, 0, nums.size());
    int all = nums[nums.size() - 1];
    int start = nums[nums.size() - 1];
    for (int i = nums.size() - 2; i >= 0; i--) {
        if (start < 0)
            start = 0;
        start += nums[i];
        if (start > all)
            all = start;
    }
    return all;
}

//dp
int maxSubArray1(vector<int>& nums) {
    int n = nums.size();
    if (n == 0)
        return 0;
    int dp_0 = nums[0];
    int dp_1 = 0;
    int res = dp_0;

    for (int i = 1; i < n; i++) {
        dp_1 = max(dp_1, dp_0 + nums[i]);
        dp_0 = dp_1;
        res = max(res, dp_1);
    }
    return res;
}


int main() {
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-4);
    nums.push_back(-5);
    cout << maxSubArray(nums);


    return 0;
}
