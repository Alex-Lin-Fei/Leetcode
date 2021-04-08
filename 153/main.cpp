#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = (right - left) / 2 + left;

        if (nums[mid] < nums[left])
            right = mid;
        else if (nums[mid] > nums[right])
            left = mid + 1;
        else
            break;
    }



    return nums[left];
}

int main() {
    vector<int> nums{4,5,6,7,0,1,2};

    std::cout << findMin(nums) << std::endl;
    return 0;
}
