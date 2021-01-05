#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& nums, int l, int r) {
    if (l < r - 1) {
        int mid = (l + r) >> 1;
        int leftCount = merge(nums, l, mid);
        int rightCount = merge(nums, mid, r);
        int count = 0;

//    左数组temp
        vector<int> leftTemp;
        for (int i = l; i < mid; i++)
            leftTemp.push_back(nums[i]);
//    右数组temp
        vector<int> rightTemp;
        for (int i = mid; i < r; i++)
            rightTemp.push_back(nums[i]);

        int k = l, i = 0, j = 0;

        while (i < leftTemp.size() && j < rightTemp.size()) {
            if (leftTemp[i] <= rightTemp[j])
                nums[k++] = leftTemp[i++];
            else {
                nums[k++] = rightTemp[j++];
                count += leftTemp.size() - i;
            }
        }

        while (i < leftTemp.size())
            nums[k++] = leftTemp[i++];
        while (j < leftTemp.size())
            nums[k++] = rightTemp[j++];

        return leftCount + rightCount + count;
    }
    return 0;
}


int reversePairs(vector<int>& nums) {
    return merge(nums, 0, nums.size());
}

int main() {
    vector<int>v;
    cout<<reversePairs(v);
    return 0;
}