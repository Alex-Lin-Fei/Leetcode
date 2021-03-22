#include <iostream>
#include <vector>
using namespace std;

int maxTurbulenceSize(vector<int>& arr) {
    if (arr.empty())
        return 0;
    int ans = 1;
    vector<int> up(arr.size());
    vector<int> down(arr.size());

    up[0] = down[0] = 1;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > arr[i - 1]) {
            up[i] = down[i - 1] + 1;
            down[i] = 1;
        } else if (arr[i] < arr[i - 1]) {
            down[i] = up[i - 1] + 1;
            up[i] = 1;
        } else {
            up[i] = down[i] = 1;
        }
        ans = max(ans, max(up[i], down[i]));
    }

    return ans;
}

int main() {
    vector<int> arr{4,8,12,16};
    std::cout << maxTurbulenceSize(arr) << std::endl;
    return 0;
}
