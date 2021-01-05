#include <iostream>
#include <vector>
using namespace std;

int waysToStep(int n) {
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else if (n == 3)
        return 4;
    long one = 1;
    long two = 2;
    long three = 4;
    long cur = three;
    for (int i = 4; i <= n; i++) {
        cur = (one + two + three) % 1000000007;
        one = two;
        two = three;
        three = cur;
    }

    return cur;
}

int main() {
    std::cout << waysToStep(5)<< std::endl;
    return 0;
}
