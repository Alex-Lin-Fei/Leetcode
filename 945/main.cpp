#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minIncrementForUnique(vector<int>& A) {
    sort(A.begin(), A.end());

    int ans = 0;
    for (int i = 1; i < A.size(); i++) {
        if (A[i] <= A[i - 1]) {
            ans += A[i - 1] + 1 - A[i];
            A[i] = A[i - 1] + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> nums{3,2,1,2,1,7};
    std::cout << minIncrementForUnique(nums) << std::endl;
    return 0;
}
