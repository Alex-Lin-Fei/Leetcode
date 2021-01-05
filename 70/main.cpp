#include <iostream>
using namespace std;

int climbStairs(int n) {
    int a = 1;
    int b = 1;
    if (n == 0 || n == 1)
        return 1;
    else {
        int temp;
        for (int i = 2; i <= n; i++) {
            temp = b;
            b += a;
            a = temp;
        }
    }
    return b;
}

int main() {
    cout<<climbStairs(3);
    return 0;
}
