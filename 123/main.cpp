#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int dp_i10 = 0, dp_i11 = INT16_MIN;
    int dp_i20 = 0, dp_i21 = INT16_MIN;
    for (auto& i: prices) {
//        dp_i20 = max(dp_i20, dp_i21 + i);
//        dp_i21 = max(dp_i21, dp_i10 - i);
        dp_i10 = max(dp_i10, dp_i11 + i);
        dp_i11 = max(dp_i11, -i);

        dp_i20 = max(dp_i20, dp_i21 + i);
        dp_i21 = max(dp_i21, dp_i10 - i);
    }

    return dp_i20;
}

int main() {
    vector<int>pr;
//    pr.push_back(3);
//    pr.push_back(3);
//    pr.push_back(5);
//    pr.push_back(0);
//    pr.push_back(0);
//    pr.push_back(3);
//    pr.push_back(1);
//    pr.push_back(4);
    pr.push_back(1);
    pr.push_back(2);
    pr.push_back(3);
    pr.push_back(4);
    pr.push_back(5);

    cout << maxProfit(pr);

    return 0;
}
