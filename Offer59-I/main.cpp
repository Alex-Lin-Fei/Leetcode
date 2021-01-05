#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> que;
    vector<int> ans;

    int i = 1 - k;
    int j = 0;
    while (j < nums.size()) {
        if (i > 0 && que.front() == nums[i - 1])
            que.pop_front();
        while (!que.empty() && que.back() < nums[j])
            que.pop_back();
        que.push_back(nums[j]);
        if (i >= 0)
            ans.push_back(que.front());
        i++;
        j++;
    }
    return ans;
}

int main() {
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    auto ans = maxSlidingWindow(nums, 3);
    for (auto& i: ans)
        cout <<i <<' ';
    return 0;
}
