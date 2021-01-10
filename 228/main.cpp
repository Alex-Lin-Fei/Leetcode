#include <iostream>
#include <vector>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;

    if (nums.empty())
        return ans;
    int start = 0;
    int end =0;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1] + 1)
            continue;
        else {
            end = i - 1;
            if (end > start)
                ans.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            else
                ans.push_back(to_string(nums[start]));
            start = i;
        }
    }
    if (start == nums.size()-1)
        ans.push_back(to_string(nums[start]));
    else
        ans.push_back(to_string(nums[start]) +"->" + to_string(nums.back()));

    for (auto &str: ans)
        cout << str << endl;
    return ans;
}

int main() {
    vector<int> nums{0,2,3,4,6,8,9};
    summaryRanges(nums);
    return 0;
}
