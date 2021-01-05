#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findDiagonalSum(vector<vector<int>>& nums) {
    vector<int>ans(nums.size() + nums[0].size() - 1);
    for (int i = 0; i < ans.size(); i++) {
        int k = (i >= nums.size()) ? (i - nums.size() + 1): 0;
        for (; k <= i; k++) {
            if (k >= nums.size())
                break;
            ans[i] += nums[k][i - k];
        }
    }

    return ans;
}
bool myCmp(pair<int, int>& a, pair<int, int>& b) {
    return (a.first + a.second == b.first + b.second)? a.first > b.first:
           a.first + a.second < b.first + b.second;
}

vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    vector<pair<int, int>> temp;
    int len = 0;
    for (auto &i: nums)
        len += i.size();
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums[i].size(); j++) {
            temp.push_back(make_pair(i, j));
        }
    }
    sort(temp.begin(), temp.end(), myCmp);
    for (auto &i: temp)
        ans.push_back(nums[i.first][i.second]);
    return ans;
}

int main() {
    vector<vector<int>> nums;
    int x = 3;
    int y = 3;
    for (int i = 0; i < x; i++) {
        vector<int> line;
        nums.push_back(line);
        for (int j = 0; j < y; j++) {
            int n;
            cin >> n;
            nums[i].push_back(n);
        }
    }
    findDiagonalOrder(nums);


    return 0;
}
