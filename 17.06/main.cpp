#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int numberOf2sInRange(int n) {
    int iCount = 0;
    long iFactor = 1;
    while (n / iFactor) {
        int cur = (n / iFactor) % 10;
        int high = (n / iFactor) / 10;
        int low = n % iFactor;
//        int low = n - (n / iFactor) * iFactor;
        switch (cur) {
            case 0:
                iCount += high * iFactor;
                break;
            case 1:
                iCount += high * iFactor;
                break;
            case 2:
                iCount += high * iFactor + low + 1;
                break;
            default:
                iCount += (high + 1) * iFactor;
                break;
        }
        iFactor *= 10;
    }
    return iCount;
}

int main() {
    std::cout << numberOf2sInRange(100) << std::endl;
    return 0;
}
