#include <iostream>
#include <cmath>
using namespace std;

void dfs(int num, int & k, int target, int sum) {
    sum++;
    target -= pow(num, 2);
    if (!target) {
        k = min(k, sum);
        return;
    }

    if (sum > k)
        return;
    for (int i = num; i > 0; i--) {
        if (target >= pow(i, 2))
            dfs(i, k, target, sum);
    }
}

int numSquares(int n) {
    int k = INT16_MAX;
    for (int i = sqrt(n); i > 0; i--)
        dfs(i, k, n, 0);
    return k;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

