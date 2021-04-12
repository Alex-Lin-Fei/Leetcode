#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int MOD = 1000000007;
int sumSubseqWidths(vector<int>& A) {
    int sum = 0;

    long p[A.size()];

    for (int i = 0; i < A.size(); i++)
        p[i] = p[i-1]*2%MOD;

sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++) {
        sum = (sum + (p[i] - p[A.size() - i - 1]) * A[i]) % MOD;
    }

    return sum;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
