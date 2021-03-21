#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    vector<vector<int>> ans;
    if (r * c != nums.size() * nums[0].size())
        ans = nums;
    else {
        ans.resize(r, vector<int>(c));
        int idx = 0, newIdx = 0;
        while (idx < r * c) {
            ans[newIdx / c][newIdx % c] = nums[idx / nums[0].size()][idx % nums[0].size()];
            idx++;
            newIdx++;
        }
    }

    for (auto &row: ans) {
        for (auto &i : row)
            cout << i << ' ';
        cout << endl;
    }

    return ans;
}

int main() {
    vector<vector<int>> nums{{1,2}, {3,4}};
    matrixReshape(nums, 4, 2);

    return 0;
}
