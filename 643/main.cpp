#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int sum = accumulate(nums.begin(), nums.begin() + k, 0);
    int pre = 0, next = k;
    int temp = sum;


    while (next < nums.size()) {

        temp += nums[next] - nums[pre];
        sum = max(sum, temp);
        next++;
        pre++;
    }

    return 1.0 * sum / k;
}


int main() {
    vector<int> nums = {1,12,-5,-6,50,3};
    std::cout << findMaxAverage(nums, 4) << std::endl;

    return 0;
}
