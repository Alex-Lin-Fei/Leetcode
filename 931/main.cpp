#include <iostream>
#include <vector>
using namespace std;

int minFallingPathSum(vector<vector<int>>& A) {
    int minL = INT16_MAX;
    if (A[0].size() == 1) {
        int s = 0;
        int i = 0;
        while (i < A.size()) {
            s += A[i][0];
            i++;
        }
        return s;
    }

    for (int i = 1; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            if (!j) {
                A[i][j] += min(A[i - 1][j], A[i-1][j+1]);
            }
            else if (j == A[0].size() - 1) {
                A[i][j] += min(A[i - 1][j], A[i-1][j-1]);
            }
            else {
                A[i][j] += min(A[i - 1][j], min(A[i-1][j+1], A[i-1][j-1]));
            }
        }
        cout << endl;
    }
    for (int i = 0; i < A[0].size(); i++)
        minL= min(minL, A[A.size() - 1][i]);

    return minL;
}

int main() {

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
