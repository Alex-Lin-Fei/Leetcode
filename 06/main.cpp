#include <iostream>
#include <vector>
using namespace std;

int minCount(vector<int>& coins) {
    int ans = 0;
    for (auto& i: coins)
        ans += (i + 1) / 2;
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
