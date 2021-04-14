#include <iostream>
using namespace std;

int hammingDistance(int x, int y) {
    int ans = 0;

    while (x || y) {
        if (x % 2 != y % 2)
            ans++;
        x /= 2;
        y /= 2;
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
