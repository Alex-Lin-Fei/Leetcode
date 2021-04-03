#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;

    for (auto& num: nums)
        ans ^= num;

    return ans;
}

int main() {
    vector<int> nums {INT32_MIN, INT32_MIN, INT32_MAX, INT32_MAX, 2};
    std::cout << singleNumber(nums) << std::endl;
    return 0;
}
