#include <iostream>
#include <vector>
using namespace std;

int largestAltitude(vector<int>& gain) {
    int ans = 0;
    int height = 0;

    for (auto &i: gain) {
        height += i;
        ans = max(ans, height);
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
