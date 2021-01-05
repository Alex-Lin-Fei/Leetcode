#include <iostream>
using namespace std;

int arrangeCoins(int n) {
    int l = 0;
    int r = n;

    while (l < r - 1) {
        int mid = (l + r) >> 1;
        if (mid * (mid + 1) /2>  n)
            r = mid-1;
        else
            l = mid;
    }
    if (r * (r+1)/2 <=  n)
        return r;
    else
        return r-1;
}

int main() {

    std::cout << arrangeCoins(2) << std::endl;
    return 0;
}
