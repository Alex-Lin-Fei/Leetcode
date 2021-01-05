#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int pre = nums.size()-2, post = nums.size() -1, idx=nums.size()-1;
    while (pre >= 0 && nums[pre] >= nums[post])
    {
        pre--;
        post--;
    }
    if (pre>=0) {
        while (nums[pre] >= nums[idx])
            idx--;
        swap(nums[idx], nums[pre]);
        reverse(nums.begin() + post, nums.end());
    }
    else
        reverse(nums.begin(), nums.end());
}

int getN(int n)
{
    if (n == 1)
        return 1;
    else
        return n * getN(n-1);
}

int main() {
    vector<int> v = {1,2,3,4};
for(int i = 0; i < getN(v.size()); i++) {
    nextPermutation(v);
    for (auto& i:v)
        cout << i<<' ';
    cout << endl;
}

    return 0;
}
