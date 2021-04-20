#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int>& nums) {
    int a = nums[0], b = nums[1];

    if (a < b)
        swap(a,b);

    for (int i = 2; i < nums.size(); i++) {
        if (nums[i] > a) {
            b = a;
            a = nums[i];
        }
        else if (nums[i] > b)
            b = nums[i];
    }
    return (a - 1) * (b - 1);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
