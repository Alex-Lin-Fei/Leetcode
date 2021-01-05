#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    if (nums1.size() > nums2.size())
        swap(nums2, nums1);
    sort(nums2.begin(), nums2.end());
    for (auto& i: nums1) {
        int l = 0, r = nums2.size()-1;
        int mid;
        while (l<=r) {
            mid = (l+r)>>1;
            if (nums2[mid] > i)
                r = mid-1;
            else if (nums2[mid]<i)
                l=mid+1;
            else
                break;
        }
        if (l <= r) {
            ans.push_back(i);
            nums2.erase(nums2.begin()+mid);
        }
    }
//    for (auto&i: ans)
//        cout << i << ' ';

    return ans;
}

int main() {
    vector<int>v1 = {4,9,5};
    vector<int>v2 = {9, 4,9,8,4};
    intersect(v1, v2);
    return 0;
}
