#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 两负 负数尽可能小 正数尽可能大
 * 一负 负数尽可能大  正数尽可能小
 * 三正/三负 尽可能大
 *
 *
 * */
int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int l = nums.size();
    return max(nums[0] * nums[1] * nums[l - 1], nums[l - 1] * nums[l - 2] * nums[l - 3]);
}

int main() {
    vector<int>nums = {1,-2,-3,-4};
    cout <<find(nums.begin(), nums.end(), 0)-nums.begin();
    return 0;
}
