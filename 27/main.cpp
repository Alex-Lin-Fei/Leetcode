#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int l = 0, r = 0;
    int ans = nums.size();

    while (r < nums.size()) {
        //    寻找下一个val
        while (l < nums.size() && nums[l] != val)
            l++;

        if (l == nums.size())
            break;
        ans = l;
        r = l + 1;

//        寻找下一个非val
        while (r < nums.size() && nums[r] == val)
            r++;
        if (r == nums.size())
            break;
//        交换
        swap(nums[l], nums[r]);
    }

    for (int i = 0; i < ans; i++)
        cout << nums[i] << ' ';
    return ans;
}

int main() {
    vector<int> nums{2,2,1,3,4,0};
    int val = 5;
    removeElement(nums, val);

    return 0;
}
