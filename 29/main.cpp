#include <iostream>
#include <vector>
using namespace std;

int myDiv(long a, long b) {
    if (a < b)
        return 0;
    long count {1};
    long temp{b};
    while (temp << 1 <= a){
        count <<= 1;
        temp <<= 1;
    }
    return count + myDiv(a - temp, b);
}

int divide(int dividend, int divisor) {
    if (dividend == 0)
        return 0;
    if (divisor == 1)
        return dividend;
    if (divisor == -1) {
        if (dividend > INT32_MIN)
            return -dividend;
        return INT32_MAX;
    }

    long a {dividend};
    long b {divisor};
    int sign {1};
    if (a>0 && b < 0 || a < 0 && b > 0)
        sign = -1;
    a = (a>0)? a: -a;
    b = (b>0)? b: -b;
    long res = myDiv(a,b);
    if (sign > 0)
        return res > INT32_MAX ? INT32_MAX: res;
    return -res;
}

int main() {
cout << divide(10,3);
    return 0;
}
