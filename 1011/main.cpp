#include <iostream>
#include <vector>
using namespace std;

int getTimes(vector<int>& weights, int mid) {
    int temp {0};
    int times = 1;
    for (auto& w: weights){
        if (temp + w > mid) {
            temp = w;
            times++;
        }
        else
            temp += w;
    }
    return times;
}

int shipWithinDays(vector<int>& weights, int D) {
    int l = 1;
    for (auto &w: weights)
        l = max(l, w);
    int r = weights.size() * l;
    while (l < r) {
        int m = (l + r) >> 1;
        if (getTimes(weights, m) > D)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

int main() {
    vector<int>v{1,2,3,1,1};
    int ans = shipWithinDays(v, 4  );
    std::cout <<ans << ':' << getTimes(v, ans) << std::endl;
    return 0;
}
