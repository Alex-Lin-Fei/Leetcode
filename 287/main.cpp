#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int l = 0;
    int r = nums.size() - 1;
    while (l < r - 1) {
        int mid = (l+r)>>1;
        if (nums[mid] < mid+1)
            r = mid;
        else
            l = mid;
    }
    return nums[r];
}

int main() {
    vector<int> v(2);
    for (int i = 0; i < 2; i++)
        cin>>v[i];
    cout << findDuplicate(v);
    return 0;
}
