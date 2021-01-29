#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int leftSum = 0;
    int allSum = accumulate(nums.begin(), nums.end(), 0);

    for (int i = 0; i < nums.size(); i++) {
        allSum -= nums[i];
        if (allSum == leftSum)
            return i;
        leftSum += nums[i];
    }
    return -1;
}

int main() {
    vector<int> nums{1, 7, 3, 6, 5, 6};
    std::cout << pivotIndex(nums) << std::endl;
    return 0;
}
