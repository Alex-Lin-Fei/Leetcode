#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& A, int m, vector<int>& B, int n) {
    int pa, pb, idx;
    pa = m - 1, pb = n - 1, idx = m + n - 1;

    while (pa >= 0 && pb >= 0) {
        if (A[pa] <= B[pb])
            A[idx--] = B[pb--];
        else
            A[idx--] = A[pa--];
    }

    while (pa >= 0) {
        A[idx--] = A[pa--];
    }

    while (pb >= 0) {
        A[idx--] = B[pb--];
    }

    for (auto & item: A)
        cout << item<<' ';
}

int main() {
    vector<int> A{-1, -1, -1,0,0,0};
    vector<int> B {-1,-1,-1};
    merge(A, 3, B, 3);


    return 0;
}
