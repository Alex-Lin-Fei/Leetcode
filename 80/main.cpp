#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int pre = 0;
    int cur = 1;

    while (cur < nums.size()) {
        while (cur < nums.size() && nums[pre] == nums[cur])
            cur++;
        for (int i = pre+1; i < cur -1;) {
            nums.erase(nums.begin()+i);
            cur--;
        }
        pre = cur;
        cur++;
    }

    return nums.size();
}

int main() {
    vector<int> arr{0,0,1,1,1,1,2,3,3};


    std::cout << removeDuplicates(arr) << std::endl;
    return 0;
}
