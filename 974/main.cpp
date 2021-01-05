#include <iostream>
#include <vector>
using namespace std;

int subarraysDivByK(vector<int>& A, int K) {
    int sum{0};
    vector<int> record(K);

    for (auto &elem: A) {
        sum += elem;
        int i = (sum%K + K) % K;
        cout << i <<' ';
        record[i]++;
    }
    sum = 0;
    for (auto &s: record)
        sum += s * (s - 1) / 2;
    return sum;
}

int main() {
    vector<int> A={-6, 1, -5, 10};
    int K = 9;
    std::cout << subarraysDivByK(A, K) << std::endl;
    return 0;
}
