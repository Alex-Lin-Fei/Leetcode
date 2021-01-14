#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<int>& nums, int k) {
    int start = (nums.size() - k % nums.size()) % nums.size();
//    反转两部分
    reverse(nums.begin(), nums.begin() + start);
    reverse(nums.begin() + start, nums.end());
    reverse(nums.begin(), nums.end());
}

int main() {
    vector<int> nums{1,3,2,4,7,5};
    rotate(nums, 3);

    return 0;
}
