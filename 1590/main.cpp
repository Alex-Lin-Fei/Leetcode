#include <iostream>
#include <vector>
#include <map>
using namespace std;

int minSubarray(vector<int>& nums, int p) {

    long long sum = 0;
    for (int e: nums) sum += (long long) e;
    long long mod = sum % (long long) p;

    if (mod == 0ll) return 0;

    int res = nums.size();
    map<long long, int> table;
//    vector<int> table(p, -1);
     table[0ll] = -1;

    sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += (long long) nums[i];
        long long curmod = sum % (long long) p;
        table[curmod] = i;

        long long targetmod = curmod >= mod ? (curmod - mod) : (curmod - mod + p);
//        if (table[targetmod] != -1)
        if (table.count(targetmod))
            res = min(res, i - table[targetmod]);
    }
    return res == nums.size() ? -1 : res;
}


int main() {
    vector<int> v = {8, 32, 31, 18, 34, 20, 21, 13, 1, 27, 23, 22, 11, 15, 30, 4, 2};
    int p = 148;
    std::cout << minSubarray(v, p) << std::endl;
    return 0;
}
