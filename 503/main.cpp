#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    if (nums.empty())
        return {};

    stack<int> idx;
    vector<int> res(nums.size(), -1);

    for (int i = 0; i < 2 * nums.size() - 1; i++) {
        while (!idx.empty() && nums[idx.top()] < nums[i%nums.size()]) {
            res[idx.top()] = nums[i%nums.size()];
            idx.pop();
        }
        idx.push(i % nums.size());
    }
    for (auto i : res)
        cout << i << ' ';
    return res;
}

int main() {
    vector<int> nums{};
    nextGreaterElements(nums);
    return 0;
}
