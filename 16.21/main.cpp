#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
    vector<int> ans;

    sort(array1.begin(), array1.end());
    sort(array2.begin(), array2.end());

    int sum1 = accumulate(array1.begin(), array1.end(), 0);
    int sum2 = accumulate(array2.begin(), array2.end(), 0);

    int diff = sum1 - sum2;
    if (diff % 2)
        return ans;

    diff /= 2;
    // 线性查找相差为2的一对数
    int idx1 = 0, idx2 = 0;
    while(idx1 < array1.size() && idx2 < array2.size()) {
        if (array1[idx1] > array2[idx2] + diff )
            idx2++;
        else if (array1[idx1] < array2[idx2] + diff )
            idx1++;
        else{
            ans.push_back(array1[idx1]);
            ans.push_back(array2[idx2]);
            break;
        }
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
