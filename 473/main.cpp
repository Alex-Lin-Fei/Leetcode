#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//bool find(vector<int>& nums, vector<bool>& isUsed, int index, int target) {
//    if (!target)
//        return true;
//    for (int i = index - 1; i >= 0; i--) {
//        if (!isUsed[i] && nums[i] <= target) {
//            isUsed[i] = true;
//            bool flag = find(nums, isUsed, i, target - nums[i]);
//            if (flag)
//                return true;
//            isUsed[i] = false;
//        }
//    }
//    return false;
//}

bool find(vector<int>& nums, int index, int target) {
    if (!target)
        return true;
    for (int i = index - 1; i >= 0; i--) {
        if (nums[i] && nums[i] <= target) {
            int temp = nums[i];
            nums[i] = 0;
            bool flag = find(nums, i, target - nums[i]);
            if (flag)
                return true;
            nums[i] = temp;
        }
    }
    return false;
}

bool makesquare(vector<int>& nums) {
    if (nums.size() < 4)
        return false;
    int tot = 0;
    for (int &i : nums)
        tot += i;
    if (tot % 4)
        return false;
    sort(nums.begin(), nums.end());
    if (nums[nums.size() - 1] > tot / 4)
        return false;
//    vector<bool> isUsed;
//    isUsed.resize(nums.size());
    int num = 0;
    while (num < 3) {
        for (unsigned int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i]) {
                nums[i] = 0;
                if (!find(nums, i, tot / 4 - nums[i]))
                    return false;
            }
        }
        num++;
    }

    return true;
}


//bool makesquare(vector<int>& nums) {
//    if (nums.size() < 4)
//        return false;
//    int tot = 0;
//    for (int &i : nums)
//        tot += i;
//    if (tot % 4)
//        return false;
//    sort(nums.begin(), nums.end());
//    if (nums[nums.size() - 1] > tot / 4)
//        return false;
//    vector<bool> isUsed;
//    isUsed.resize(nums.size());
//    int num = 0;
//    while (num < 3) {
//        for (int i = nums.size() - 1; i >= 0; i--) {
//            if (!isUsed[i]) {
//                isUsed[i] = true;
//                if (!find(nums, isUsed, i, tot / 4 - nums[i]))
//                    return false;
//            }
//        }
//        num++;
//    }
//
//    return true;
//}

int main() {
    vector<int> nums;
//    nums.push_back(3);
//    nums.push_back(3);
//    nums.push_back(3);
//    nums.push_back(3);
//    nums.push_back(4);
    for (int i = 1; i <= 15; i++)
    nums.push_back(i);
    cout << makesquare(nums);
    return 0;
}
