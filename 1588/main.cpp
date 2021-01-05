#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sumOddLengthSubarrays(vector<int>& arr) {
    int ans{0}, sum;
    for (int i = 0; i <= arr.size()/2; i++) {
//        计算累加次数
        sum = 0;
        for (int l = 1; l <= arr.size(); l += 2)
            sum += min(l, min(min(i + 1, (int)arr.size()-i), (int) arr.size() - l + 1));

        ans += sum * arr[i];
        if (i != arr.size() - 1 - i)
            ans += sum * arr[arr.size() - 1 - i];
    }
    return ans;
}

int main() {
    vector<int>arr={10,11,12};

    std::cout << sumOddLengthSubarrays(arr) << std::endl;
    return 0;
}
/* 1 2 3 4 5 6
 * 1 2 3
 * 2 3 4
 * 3 4 5
 * 4 5 6
 * 1 2 3 4 5
 * 2 3 4 5 6
 * 1 2 3 4 5 6
 * 3 5 6 6 5 3
 *
 * xi
 * 1 1   5  5  2
 * l min(l, i, len-l+1)
 * 1 1 1 1 = 3
 * 2 1 2 2 = 5
 * 3 1 3 2 = 6
 * 4 1 3 2
 * */