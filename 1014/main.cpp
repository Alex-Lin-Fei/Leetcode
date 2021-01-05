#include <iostream>
#include <vector>
using namespace std;

int maxScoreSightseeingPair(vector<int>& A) {
    int res = 0;
    int maxAns = A[0] + 0;
    for (int i = 1; i < A.size(); i++) {
        res = max(res, maxAns + A[i] - i);
        maxAns = max(maxAns, A[i] + i);
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
