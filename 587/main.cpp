#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


const int EPS = static_cast<const int>(10e-10);
bool clockwise(vector<int>& p1, vector<int>& p2, vector<int>& p3) {
    int a = p2[0] - p1[0];
    int b = p2[1] - p1[1];
    int c = p3[0] - p2[0];
    int d = p3[1] - p2[1];

    int x = a*d-b* c;
    return x <-EPS || x==0;
}


vector<vector<int>> outerTrees(vector<vector<int>>& points) {
    set<vector<int>> once;
    vector<vector<int>> u, l;

    if (points.size() <= 3)
        return points;

    sort(points.begin(), points.end(), [&](vector<int> a, vector<int> b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
    });

    u.push_back(points[0]);
    u.push_back(points[1]);

    l.push_back(points[points.size() - 1]);
    l.push_back(points[points.size() - 2]);

//    构建上部
    for (int i = 2; i < points.size(); i++) {
        for (int n = u.size(); n >= 2 && !clockwise(u[n - 2], u[n - 1], points[i]); n--)
            u.pop_back();
        u.push_back(points[i]);
    }

    for (int i = points.size() - 3; i >= 0; i--) {
        for (int n = l.size(); n >= 2 && !clockwise(l[n - 2], l[n - 1], points[i]); n--)
            l.pop_back();
        l.push_back(points[i]);
    }

    vector<vector<int>> ans;

    for (auto& item: l) {
        once.insert(item);
        ans.push_back(item);
    }

    for (auto& item: u)
        if (!once.count(item))
            ans.push_back(item);


    return ans;
}

int main() {
    vector<vector<int>> points{{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}};
    outerTrees(points);

    return 0;
}
