#include <iostream>
#include <vector>
using namespace std;

vector<int> getRow(int rowIndex) {
    if (rowIndex == 0)
        return {1};
    vector<int> ans = {1, 1};
    if (rowIndex == 1)
        return ans;
    while (rowIndex--) {

    }

    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
