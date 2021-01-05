#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    if (nums.size() < 2)
        return false;
    else if (!k) {
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] == 0 && nums[i + 1] == 0)
                return true;
        return false;
    }
    else {
        int sum = nums[0] % k;
        set<int> s;
        for (int i = 1; i < nums.size(); i++) {
            int temp = sum;
            sum = (sum + nums[i]) % k;
            if (s.count(sum))
                return true;
            s.insert(temp);
        }
    }
    return false;
}

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
//    nums.push_back(6);
//    nums.push_back(4);
//    nums.push_back(7);
    int k = 2;

    std::cout << checkSubarraySum(nums,k) << std::endl;
    return 0;
}
