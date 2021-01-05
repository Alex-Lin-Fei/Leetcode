#include <iostream>
#include <vector>
using namespace std;

int get_time(vector<int>& piles, int v) {
    int t = 0;
    for (auto &p: piles)
        t += (p % v == 0) ? p / v : p / v + 1;
    return t;
}

int minEatingSpeed(vector<int>& piles, int H) {
    int r = 0;
    for (auto &i: piles)
        r = max(r, i);
    int l = 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (get_time(piles, mid) <= H)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main() {
    vector<int>v={312884470};
    int H=968709470;
    cout << minEatingSpeed(v, H);
    return 0;
}
