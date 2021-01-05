#include <iostream>
using namespace std;

int findNthDigit(int n) {
    int start = 1, digit = 1;
    long count = 9;
    while (n > count) {
        n -= count;
        start *= 10;
        digit++;
        count = digit* start*9;
    }
    int num = start + (n-1) / digit;
    return to_string(num)[(n-1)%digit] - '0';
}

int main() {
    std::cout << findNthDigit(1000000000) << std::endl;
    return 0;
}
