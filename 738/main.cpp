#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;


int monotoneIncreasingDigits(int N) {
    if (N/10==0)
        return N;
    vector<int> nums;

    while (N) {
        nums.push_back(N % 10);
        N /= 10;
    }
    reverse(nums.begin(), nums.end());
    int i;
    for (i = 0; i < nums.size() - 1; i++) {
        if (nums[i + 1] >= nums[i])
            continue;
        else
            break;
    }
    if (i != nums.size() - 1) {
        while (i>0) {
            if (nums[i - 1] == nums[i])
                i--;
            else
                break;
        }
        nums[i]--;
        i++;
        while (i < nums.size())
            nums[i++] = 9;
    }
    int ans = 0;
    for (auto &j: nums)
        ans = ans * 10 + j;
    return ans;
}


int main() {
    cout <<monotoneIncreasingDigits(32332);
//    std::cout << monotoneIncreasingDigits(321) << std::endl;
    return 0;
}
