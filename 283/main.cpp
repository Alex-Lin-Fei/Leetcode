#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int i = 0, j = 0;

    while (j < nums.size()) {
        if (!nums[j])
            j++;
        else
            nums[i++] = nums[j++];
    }
    while (i < nums.size())
        nums[i++] = 0;
}

int main() {
    vector<int> v{0,0,0,0,0};
    moveZeroes(v);
    return 0;
}
