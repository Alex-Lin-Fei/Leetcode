#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int lowerBound(vector<int>& nums, int target) {
    int l = 0, r = nums.size();

    while (l < r) {
        int mid = (l + r) >> 1;
        if (nums[mid] < target)
            l = mid + 1;
        else
            r = mid;
    }
    return l == nums.size() || nums[l]!=target ? -1 : l;
}


int upperBound(vector<int>& nums, int target) {
    int l = 0, r = nums.size();

    while (l < r-1) {
        int mid = (l + r) >> 1;
        if (nums[mid] <= target)
            l = mid;
        else
            r = mid;
    }
    return l == nums.size() || nums[l] != target ? -1 : l;
}

vector<int> searchRange(vector<int>& nums, int target) {
//    return {lowerBound(nums, target), upperBound(nums, target)};
    auto lower = lower_bound(nums.begin(), nums.end(), target);
    auto upper = upper_bound(nums.begin(), nums.end(), target);
    int l, r=0;
    if (lower != nums.end() && *lower == target)
        l = lower - nums.begin();
    else
        l = -1;
    if (l == -1)
        r = -1;
    else
        r = upper - nums.begin()-1;


    cout <<l<<' ' << r<<endl;

    return {l, r};
}

int main() {
    vector<int> v{0};
    searchRange(v, 1);
    return 0;
}
