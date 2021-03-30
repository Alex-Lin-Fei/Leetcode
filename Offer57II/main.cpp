#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> ans;

    for (int start = 1; start < (target + 1) / 2; start++) {
//        二分法寻找end
        int l = start+1;
        int r = target - start;
        int mid;
        while (l <= r) {
            mid = (r-l)/2+l;
            int sum = (mid+start) * (mid - start + 1) / 2;
            if (sum > target)
                r = mid-1;
            else if (sum < target)
                l = mid+1;
            else
                break;
        }
        if (l<=r) {
//            找到了
            ans.emplace_back();
            for (int i = start; i <= mid; i++)
                ans.back().push_back(i);
        }
    }

    for (auto& row: ans) {
        for (auto &i: row)
            cout << i << ' ';
        cout << endl;
    }

    return ans;
}

int main() {
    findContinuousSequence(15);

    return 0;
}
