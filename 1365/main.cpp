#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());

    for (auto &num: nums)
        num = find(temp.begin(), temp.end(), num) - temp.begin();
    for (auto &n: nums)
        cout << n << ' ';
    return nums;
}


int main() {
    vector<int> v{8, 1, 2, 2, 3};

    smallerNumbersThanCurrent(v);

    return 0;
}
