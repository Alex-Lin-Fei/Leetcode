#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums, int l, int mid, int r) {
    vector<int> tmp(r-l+1);

    int i = l, j = mid+1;
    int idx= 0;
    while (idx < tmp.size()) {
        if (j > r || (i <= mid && nums[i] <= nums[j]))
            tmp[idx++] = nums[i++];
        else
            tmp[idx++] = nums[j++];
    }
    for(i = 0; i < tmp.size(); i++)
        nums[l+i] = tmp[i];
/*
    int n1 = (mid - l + 1);
     int n2 = (r - mid);
     int L[n1], R[n2];
     for (int i = 0; i < n1; i++)
         L[i] = nums[l + i];
     for (int j = 0; j < n2; j++)
         R[j] = nums[mid + 1 + j];
     int i = 0, j = 0;
     for (int k = l; k <= r; k++) {
         if (j >= n2 || (i < n1 && L[i] <= R[j]))
             nums[k] = L[i++];
         else
             nums[k] = R[j++];
     }
     */
}

int merge_count(vector<int>& nums, int l, int r) {

    if (l < r) {
        int sum = 0;
        int mid = (l + r) >> 1;
        sum += merge_count(nums, l, mid);
        sum += merge_count(nums, mid + 1, r);
//        计算左右部分元素构成的重要翻转对
        int i = l;
        int j = mid + 1;

        while (i <= mid) {
            while (j <= r && nums[i] > 2LL * nums[j]) {
                sum += mid - i + 1;
                j++;
            }
            i++;
        }
        merge(nums, l, mid, r);
        return sum;
    }
    return 0;
}

int reversePairs(vector<int>& nums) {
    return merge_count(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> v{233,2000000001,234,2000000006,235,2000000003,236,2000000007,237,2000000002,2000000005,233,233,233,233,233,2000000004};
    std::cout << reversePairs(v) << std::endl;
    return 0;
}
