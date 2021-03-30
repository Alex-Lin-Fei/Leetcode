#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> distributeCandies(int candies, int num_people) {
//    二分法找到最后一个n n*(n+1)/2不大于candies
    vector<int> ans(num_people);
    int l = 2, r = sqrt(2*candies)+1;

    while (l < r - 1) {
        int mid = (r - l) / 2 + l;
        int a = mid + 1;
        int b = mid;
        if (a % 2)
            b /= 2;
        else
            a /= 2;
        int sum = a * b;

        if (sum <= candies)
            l = mid;
        else
            r = mid;
    }

//    res = candies - n * (n + 1) / 2
    for (int i = 1; i <= l; i++) {
        ans[(i - 1) % ans.size()] += i;
        candies -= i;
    }
    ans[l % ans.size()] += candies;

    for (auto &i: ans)
        cout << i << ' ';

    return ans;
}

int main() {
    distributeCandies(1000000000, 1000);
//distributeCandies(7,4);

    return 0;
}
