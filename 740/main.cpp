#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int deleteAndEarn(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int>count(nums[nums.size() - 1] + 1, 0);
    for (auto& i: nums)
        count[i]++;
    nums.clear();

    for (int i = 0; i < count.size(); i++) {
        if (count[i]) {
            nums.push_back(i);
        }
    }

    int pre = nums[0];
    int use = 0;
    int used = pre;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] - 1 == pre) {
            int temp = max(use, used);
            used = use + count[nums[i]] * nums[i];
            use = temp;
        } else {
            int temp = max(use, used) + count[nums[i]] * nums[i];
            use = max(use, used);
            used = temp;
        }
        pre = nums[i];

    }

    return max(use, used);
}

int main() {
    vector<int> num;
    num.push_back(3);
    num.push_back(3);
    num.push_back(3);

    num.push_back(4);
    num.push_back(2);
    cout << deleteAndEarn(num);

    return 0;
}
