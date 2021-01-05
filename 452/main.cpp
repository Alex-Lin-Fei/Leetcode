#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    int cnt = 0;

    sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] <= b[1]);
    });

    int e = INT32_MIN;
    for (auto & point : points) {
        if (e >= point[0]) {
            e = min(e, point[1]);
            if (point[0] ==INT32_MIN)
                cnt++;
        } else {
            cnt++;
            e = point[1];
        }
    }

    return cnt;
}

int main() {
    vector<vector<int>> points{{-2147483648,2147483647}};
    cout << findMinArrowShots(points);

    return 0;
}
