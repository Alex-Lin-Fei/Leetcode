#include <iostream>
#include <vector>
using namespace std;

int massage(vector<int>& nums) {
    int use = nums[0];
    int avoid = 0;
    for (int i = 1; i < nums.size(); i++) {
        int temp = avoid;
        avoid = max(use, avoid);
        use = temp + nums[i];
    }
    return max(avoid, use);
}

int main() {
    vector<int> nums;
    std::cout << massage(nums) << std::endl;
    return 0;
}
