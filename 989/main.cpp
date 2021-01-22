#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> addToArrayForm(vector<int>& A, int K) {
    reverse(A.begin(), A.end());
    int c = 0;
    int idx = 0;

    while(K && idx < A.size()) {
        int sum = A[idx] + K % 10 + c;
        A[idx] = sum % 10;
        c = sum / 10;
        K /= 10;
        idx++;
    }

    while (idx < A.size()) {
        int sum = A[idx] + c;
        A[idx] = sum % 10;
        c = sum / 10;
        idx++;
    }

// 数组向后填充数字
    while (K) {
        int num = (K % 10 + c) % 10;
        c = (K % 10 + c) / 10;
        K /= 10;
        A.push_back(num);
    }

    if (c)
        A.push_back(1);
    reverse(A.begin(), A.end());
    return A;
}

int main() {
    vector<int> A{7};
    int K = 993;
    auto ans = addToArrayForm(A, K);
    for (auto& i: ans)
        std::cout << i << ' ';
    return 0;
}
