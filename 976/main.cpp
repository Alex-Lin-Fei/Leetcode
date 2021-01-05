#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largestPerimeter(vector<int>& A) {
    sort(A.begin(), A.end());

    int ans = 0;
    for (int i = A.size() - 1; i >= 2; i--)
        for (int j = i - 1; j >= 1; j--) {
            for (int k = j - 1; k >= 0; k--)
                if (A[i] - A[j] < A[k])
                    return A[i] + A[j] + A[k];
        }
    return 0;
}
