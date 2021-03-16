#include <iostream>
#include <vector>
using namespace std;

bool isMonotonic(vector<int>& A) {
    int flag = 0;

    for (int i = 1; i < A.size(); i++) {
        if (flag * (A[i] - A[i - 1]) >= 0) {
            if (flag == 0) {
                if (A[i] > A[i - 1])
                    flag = 1;
                else if (A[i] < A[i - 1])
                    flag = -1;
            }
        } else
            return false;
    }
    return true;
}

int main() {
    vector<int> A{1,2,2,3,1};
    std::cout << isMonotonic(A) << std::endl;
    return 0;
}
