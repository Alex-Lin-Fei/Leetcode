#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int smallestRangeII(vector<int>& A, int K) {
    sort(A.begin(), A.end());
    int ans = A[A.size()-1]-A[0];

    for (int i = 1; i < A.size(); i++) {
        int minL = min(A[i]-K, A[0]+K);
        int maxL = max(A[i-1]+K, A[A.size()-1]-K);
        ans = min(ans, maxL-minL);
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
