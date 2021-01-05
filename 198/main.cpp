#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums) {
    vector<int> money(nums.size()+1);
    money[0] = 0;
    int ans=0;
    for(int i = 0;i < nums.size(); i++) {
        if (i < 1)
            money[i+1] = nums[i];
        else
            money[i+1] = max(money[i], money[i - 1] + nums[i]);
        ans = max(ans, money[i+1]);
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
