#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int longestSubarray(vector<int>& nums, int limit) {
    deque<int> mx;
    deque<int> mn;

    int left = 0, right = 0;
    int ans = 1;
    while (right < nums.size()) {
        while (!mx.empty() && mx.back() < nums[right]) {
            mx.pop_back();
        }
        mx.push_back(nums[right]);
        while (!mn.empty() && mn.back() > nums[right]) {
            mn.pop_back();
        }
        mn.push_back(nums[right]);

        while (!mx.empty() && !mn.empty() && mx.front() - mn.front() > limit) {
            if (mx.front() == nums[left])
                mx.pop_front();
            if (mn.front() == nums[left])
                mn.pop_front();
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }

    return ans;
}

int main() {
    vector<int> nums {8,2,4,7};
    std::cout << longestSubarray(nums, 4) << std::endl;
    return 0;
}
