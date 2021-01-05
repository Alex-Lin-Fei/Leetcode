#include <iostream>
#include <vector>

using namespace std;

string getPermutation(int n, int k) {
    string ans;
    vector<int> factorial(n+1);
    vector<int> nums;
    factorial[0] = 1;
    for (int i = 1; i <= n; i++)
        factorial[i] = factorial[i-1] * i;

    for (int i = 1; i <= n; i++)
        nums.push_back(i);

    for (int i = 1; i <= n; i++) {
        int idx = k / factorial[n - i];
        if (k % factorial[n - i])
            idx++;
        ans += nums[idx - 1] + '0';
        nums.erase(nums.begin() + idx - 1);
        k -= (idx - 1) * factorial[n - i];
    }
    return ans;
}

int main() {
    std::cout << getPermutation(4,9) << std::endl;
    return 0;
}
