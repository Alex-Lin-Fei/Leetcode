#include <iostream>
#include <vector>
using namespace std;

int maxTurbulenceSize(vector<int>& A) {
    if (A.empty())
        return 0;
    vector<int> up(A.size());
    vector<int> down(A.size());
    up[0] = down[0] = 1;
    int ans = 1;
    for (int i = 1; i < A.size(); i++) {
        if (A[i] > A[i - 1]) {
            up[i] = down[i - 1] + 1;
            down[i] = 1;
        } else if (A[i] < A[i - 1]) {
            down[i] = up[i - 1] + 1;
            up[i] = 1;
        } else {
            down[i] = up[i] = 1;
        }
        ans = max(ans, max(down[i], up[i]));
    }
    return ans;
}

int main() {
    vector<int>nums;
//    nums.push_back(9);
//    nums.push_back(4);
//    nums.push_back(2);
//    nums.push_back(10);
//    nums.push_back(7);
//    nums.push_back(8);
//    nums.push_back(8);
//    nums.push_back(1);
//    nums.push_back(9);
//nums.push_back(4);
//    nums.push_back(8);
//    nums.push_back(12);
    nums.push_back(19);
    nums.push_back(16);
    nums.push_back(16);
    nums.push_back(16);
    nums.push_back(17);



    std::cout << maxTurbulenceSize(nums) << std::endl;
    return 0;
}
