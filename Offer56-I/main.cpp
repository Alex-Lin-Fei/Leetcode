#include <iostream>
#include <vector>
using namespace std;

vector<int> singleNumbers(vector<int>& nums) {
    vector<int> ans(2);
    int ab = 0;
    for (auto &i: nums)
        ab ^= i;
    int flag = 1;
    while (ab) {
        if (ab & flag)
            break;
        flag <<= 1;
    }
    for (auto &i: nums) {
        if (i & flag)
            ans[0] ^= i;
        else
            ans[1] ^= i;
    }
    cout << ans[0] << ' ' << ans[1] << endl;
    return ans;
}

int main() {
    vector<int> v{2, 2, 4, 4, 5, 6, 7, 6, 5, 9};
    singleNumbers(v);

    return 0;
}
