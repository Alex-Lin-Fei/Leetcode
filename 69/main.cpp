#include <iostream>
using namespace std;

int mySqrt(int x) {
    if (x <= 1)
        return x;
    int l = 0;
    int r = x;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (mid * mid > x)
            r = mid;
        else
            l = mid;
    }
    return l;
}

int main() {
    std::cout << mySqrt(8) << std::endl;
    return 0;
}
