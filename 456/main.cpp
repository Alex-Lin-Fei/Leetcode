#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool find132pattern(vector<int>& nums) {
    vector<int> left_min(nums.size());
    stack<int> stk;

    for (int i = 0; i < nums.size(); i++)
        left_min[i] = (i == 0? nums[i] : min(nums[i-1], left_min[i-1]));


    stk.push(nums.back());
    for (int i = nums.size() - 2; i > 0; i--) {
        if (nums[i] > left_min[i]) {
            while (!stk.empty() && left_min[i] >= stk.top())
                stk.pop();
            if (!stk.empty() && nums[i] > stk.top())
                return true;
            else
                stk.push(nums[i]);
        }
    }

    return false;
}


int main() {
    vector<int> nums {1,4,0,-1,-2,-3,-1,-2};
    std::cout << find132pattern(nums) << std::endl;
    return 0;
}
