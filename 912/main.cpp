#include <iostream>
#include <vector>
using namespace std;


int partition(vector<int>& nums, int left, int right) {
    if (left >= right)
        return -1;
    int i = left - 1;
    int j = left;

    while (j < right) {
        if (nums[j] < nums[right]) {
            i++;
            swap(nums[i], nums[j]);
        }
        j++;
    }
    swap(nums[++i], nums[right]);
    return i;
}


void quickSort(vector<int>& nums, int left, int right) {
    if (left < right) {
        int idx = partition(nums, left, right);
        quickSort(nums, left, idx - 1);
        quickSort(nums, idx + 1, right);
    }
}

vector<int> sortArray(vector<int>& nums) {
    quickSort(nums, 0, nums.size()-1);

    return nums;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
