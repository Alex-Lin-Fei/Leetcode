#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int idx = 0;
    int len = 0;
    int ansLen = 0;

    while (idx < nums.size()) {
        if (nums[idx] == 1) {
            len++;
        } else {
            ansLen = max(len, ansLen);
            len = 0;
        }
        idx++;
    }

    return max(len, ansLen);
}

int main() {
    vector<int> nums = {0,1,1,0,1,1,1};
    std::cout << findMaxConsecutiveOnes(nums) << std::endl;
    return 0;
}
