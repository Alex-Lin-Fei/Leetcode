#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int i = 0;
    int j = nums.size() - 1;

    while (i <= j) {
        if (nums[i] + nums[j] != nums.size()) {
            return (nums[i] > nums.size() - nums[j])? nums.size() - nums[j]: nums.size() - nums[i];
        }
        i++;
        j--;
    }
    return nums[nums.size() - 1] / 2;
}

int main() {
    vector<int>nums;
    nums.push_back(0);
    nums.push_back(1);
//    nums.push_back(2);
    nums.push_back(3);

    std::cout << missingNumber(nums) << std::endl;
    return 0;
}
