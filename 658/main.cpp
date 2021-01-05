#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    vector<int> ans;

    for (auto &i: arr)
        i -= x;
    if (arr[0] >= 0) {
        for (int i = 0; i < k; i++)
            ans.push_back(arr[i] + x);
    } else if (arr[arr.size() - 1] <= 0) {
        for (int i = arr.size() - 1; i >= arr.size() - k; i--)
            ans.push_back(arr[i] + x);
    } else {
        int l = 0, r = arr.size() - 1;
        int mid;
        while (l <= r) {
            int m = (l+r)>>1;
            if (arr[m] >= 0)
            {
                mid = m;
                r = m-1;
            }
            else
                l=m+1;
        }
        int len = arr.size();
        r = min(mid+k, len - 1);
        l = max(mid- k, 0);

        while (r-l+1>k) {
            if (abs(arr[r]) >= abs(arr[l]))
                r--;
            else
                l++;
        }
        for (;l<=r;l++)
            ans.push_back(arr[l]);
    }
    sort(ans.begin(), ans.end());

    return ans;
}

int main() {
    vector<int>a={1,2,3,4,5};
    cout<<findClosestElements(a, 3,8)[0];
    return 0;
}
