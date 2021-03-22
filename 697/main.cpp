#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int findShortestSubArray(vector<int>& nums) {
    map<int, int> count;
    set<int> most;
    int maxCount = 0;
    int minLen = nums.size();

    for (auto& i: nums) {
        count[i]++;
        maxCount = max(maxCount, count[i]);
    }

    if (maxCount == 1)
        return 1;

    for (auto& item: count) {
        if (item.second == maxCount)
            most.insert(item.first);
    }

    int left, right;
    for (auto& i: most) {
        left = 0;
        right = nums.size() - 1;
        while (nums[left] != i)
            left++;
        while (nums[right] != i)
            right--;
        minLen = min(minLen, right - left + 1);
    }

    return minLen;
}

int main() {
    vector<int> nums{1,2,2,3,1};
    std::cout << findShortestSubArray(nums) << std::endl;
    return 0;
}
