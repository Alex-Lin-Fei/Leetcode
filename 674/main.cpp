#include <iostream>
#include <vector>
using namespace std;

int findLengthOfLCIS(vector<int>& nums) {
    int i = 1;
    int maxL = 1;
    int tempL = 1;
    while (i< nums.size()) {
        if (nums[i] > nums[i-1])
            tempL++;
        else {
            maxL = max(maxL, tempL);
            tempL= 1;
        }
        i++;
    }
    return max(maxL, tempL);
}

int main() {
    vector<int> v(4);
    for (int i = 0; i < 4; i++)
        cin >> v[i];
    cout << findLengthOfLCIS(v);

    return 0;
}
