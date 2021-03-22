#include <iostream>

using namespace std;

int hammingWeight(uint32_t n) {
    int ans = 0;

    while (n) {
        ans += n % 2;
        n /= 2;
    }

    return ans;
}

int main() {

    std::cout << x << std::endl;
    return 0;
}
