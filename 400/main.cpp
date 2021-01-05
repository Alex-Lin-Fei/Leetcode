#include <iostream>
#include <cmath>

int findNthDigit(int n) {
    int p = 9;
    int bit = 1;
    while (n - p * bit > 0) {
        n -= p * bit;
        p *= 10;
        bit++;
    }

    int number = pow(10, bit - 1) + (n - 1) / bit;
    int pos = n % bit;
    if (pos == 0)
        return number % 10;
    else
    {
        int temp = number - pow(10, bit - pos);
        return temp % 10;
    }
}

int main() {
    std::cout << findNthDigit(11) << std::endl;
    return 0;
}
