#include <iostream>
#include <vector>

using namespace std;

int longestOnes(vector<int>& A, int K) {
    int left = 0, right = 0;
    int zero_count = 0;

    int ans = 1;

    while (right < A.size()) {
        zero_count += 1 - A[right];

        while (zero_count > K) {
            zero_count -= 1 - A[left];
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }

    return ans;
}

int main() {
    vector<int> A = {1,1,1,0,0,0,1,1,1,1,0};

    std::cout << longestOnes(A, 2) << std::endl;
    return 0;
}

