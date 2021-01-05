#include <iostream>
#include <vector>
using namespace std;

int getSum(vector<int>& nums, int num) {
    int sum = 0;
    for (auto& n:nums) {
        double temp = 1.0 * n / num;
        sum += (temp > (int) (temp)) ? (int) temp + 1 : (int) temp;
    }
    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    if (threshold == nums.size())
    {
        int maxl = 0;
        for (auto& n: nums)
            maxl = max(n, maxl);
        return maxl;
    }
    else {
        int l = 1;
        int r{0};
        for (auto &n: nums)
            r += n;
        r = 1.0 * r / (threshold - nums.size()) + 1;

        while (l < r) {
            int mid = (l + r) >> 1;
            if (getSum(nums, mid) <= threshold)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
}

int main() {
    vector<int>v{1,2,5,9};
    std::cout << smallestDivisor(v, 4) << std::endl;
    return 0;
}
