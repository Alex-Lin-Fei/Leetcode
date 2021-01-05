#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> sum;

    NumArray(vector<int>& nums) {
        sum = nums;
        for (int i = 1; i < sum.size(); i++)
            sum[i] += sum[i - 1];
    }

    int sumRange(int i, int j) {
        if (i != 0)
            return sum[j] - sum[i - 1];
        else
            return sum[j];
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
