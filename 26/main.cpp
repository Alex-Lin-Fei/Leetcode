#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    for (int i = 0; i + 1 < nums.size();) {
        if (nums[i + 1] == nums[i])
            nums.erase(nums.begin() + i + 1);
        else
            i++;
    }

    for (auto &i: nums)
        cout << i << ' ';
    return nums.size();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
