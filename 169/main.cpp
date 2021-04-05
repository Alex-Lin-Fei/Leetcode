#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 1;
    int target = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (!count) {
            target = nums[i];
            count = 1;
        } else {
            if (nums[i] == target)
                count++;
            else
                count--;
        }
    }
    return target;
}

int main() {
    vector<int> nums{2,2,1,1,1,2,2};
    std::cout << majorityElement(nums) << std::endl;
    return 0;
}
