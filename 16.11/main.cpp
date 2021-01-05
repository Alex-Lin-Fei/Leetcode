#include <iostream>
#include <vector>
using std::endl;
using std::cout;
using std::cin;
using std::vector;

vector<int> divingBoard(int shorter, int longer, int k) {
    vector<int> ans;
    if (!k)
        return ans;
    int d = longer - shorter;
    if (!d) {
        ans.push_back(shorter * k);
        return ans;
    }
    for (int i = 0; i <= k; i++) {
        ans.push_back(shorter * k + i * d);
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
