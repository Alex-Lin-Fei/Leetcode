#include <iostream>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;

    for(int i = 0; i < 32; i++) {
        ans |= (n & 1) << (31 - i);
        n >>= 1;
    }

    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
