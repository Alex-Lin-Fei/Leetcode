#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int>& nums) {
    int ans = INT32_MIN;

    vector<int> f_max(nums.size());
    vector<int> f_min(nums.size());
    f_max[0] = f_min[0] = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        f_max[i] = max(f_max[i-1]*nums[i], f_min[i-1] * nums[i]);
        f_min[i] = min(f_max[i-1]*nums[i], f_min[i-1] * nums[i]);
        ans = max(ans, f_max[i]);
    }


    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
