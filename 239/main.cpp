#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> que;
    vector<int> ans;
//    for (int i = 0; i < k; i++) {
//        while (!que.empty() && nums[i] >= nums[que.back()])
//            que.pop_back();
//        que.push_back(i);
//    }
//    ans.push_back(nums[que.front()]);

    for (int i = 0; i < nums.size(); i++) {
        while (!que.empty() && nums[i] >= nums[que.back()])
            que.pop_back();
        que.push_back(i);

        if (i >= k) {
            while (!que.empty() && que.front() <= i - k)
                que.pop_front();
        }
        if (i >= k - 1)
            ans.push_back(nums[que.front()]);
    }
for (auto& i: ans)
    cout <<i <<' ';

    return ans;
}

int main() {
    vector<int> nums{4,-2};
    maxSlidingWindow(nums, 2);


    return 0;
}
