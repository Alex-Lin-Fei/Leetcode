#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int partition(vector<int>& nums, int p, int r) {
    int x = nums[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (nums[j] <= x) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i+1], nums[r]);
    return i+1;
}

int random_partition(vector<int>& nums, int p, int r) {
    srand((int)time(0));
    int i = rand()%(r-p + 1) + p;
    swap(nums[i], nums[r]);
    return partition(nums, p, r);
}

int random_select(vector<int>& nums, int p, int r, int i) {
    if (p == r)
        return nums[p];
    int q = random_partition(nums, p, r);
    int k = q - p + 1;
    if (i == k)
        return nums[q];
    else if (i < k)
        return random_select(nums, p, q - 1, i);
    else
        return random_select(nums, q + 1, r, i - k);
}

int findKthLargest(vector<int>& nums, int k) {
    return random_select(nums, 0, nums.size() - 1, nums.size() + 1 - k);
}

int main() {
    vector<int>n;
    n.push_back(3);
    n.push_back(2);
//    n.push_back(3);
    n.push_back(1);
    n.push_back(5);
    n.push_back(6);
    n.push_back(4);
//    n.push_back(5);
//    n.push_back(5);
//    n.push_back(6);


    cout << findKthLargest(n, 2);

    return 0;
}
