#include <iostream>
using namespace std;

int smallestRepunitDivByK(int K) {
    if (K % 2 == 0 || K % 5 == 0)
        return -1;
    int x = 1;
    int len = 1;
    while (x % K != 0) {
        x = x % K;
        x = x * 10 + 1;
        len++;
    }
    x = 0;
    while (len--)
        x = x * 10 + 1;
    return x;
}

int main() {
    std::cout << smallestRepunitDivByK(3) << std::endl;
    return 0;
}
