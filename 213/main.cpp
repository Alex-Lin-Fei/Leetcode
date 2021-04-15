#include <iostream>
#include <vector>
using namespace std;

//int dp(vector<int>& nums, int start, int end) {
//    int dp_i_0 = 0;
//    int dp_i_1 = 0;
//    for (int i = start; i <= end; i++) {
//        int temp = dp_i_0;
//        dp_i_0 = max(dp_i_0, dp_i_1);
//        dp_i_1 = temp + nums[i];
//    }
//    return max(dp_i_1, dp_i_0);
//}
//
//int rob(vector<int>& nums) {
//    if (nums.size() == 1)
//        return nums[0];
//    return max(dp(nums, 0, nums.size() - 2), dp(nums, 1, nums.size() - 1));
//}

int dp(vector<int> & nums, int start, int end) {
    int dp_i_0 = 0;
    int dp_i_1 = 0;
    for (int i = start; i <= end; i++) {
        int temp = dp_i_0;
        dp_i_0 = max(dp_i_1, dp_i_0);
        dp_i_1 = temp + nums[i];
    }
    return max(dp_i_0, dp_i_1);
}

int rob(vector<int>& nums) {
if (nums.size() == 1)
    return nums[0];
return max(dp(nums, 0, nums.size() - 1), dp(nums, 1, nums.size() - 1));
}

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);


    std::cout <<rob(nums) << std::endl;
    return 0;
}
