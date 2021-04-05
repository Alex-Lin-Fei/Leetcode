#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


//dp overtime
//bool canThreePartsEqualSum(vector<int>& arr) {
//    vector<int> dp(arr.size());
//    dp[0] = arr[0];
//
//    for (int i = 1; i < dp.size(); i++)
//        dp[i] = dp[i - 1] + arr[i];
//
//    if (dp.back() % 3)
//        return false;
//    int sum = dp.back() / 3;
//
//    for (int i = 0; i < dp.size() - 2; i++) {
//        for (int j = i + 1; j < dp.size() - 1; j++) {
//            if (dp[i] == sum && dp[j] == 2 * sum)
//                return true;
//        }
//    }
//
//    return false;
//}

bool canThreePartsEqualSum(vector<int>& arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);

    if (sum % 3)
        return false;
    sum /= 3;

    int i = 0;

    int cur = 0;
    while (i < arr.size()) {
        cur += arr[i];
        if (cur == sum)
            break;
        i++;
    }
    if (i == arr.size())
        return false;

    int j = i + 1;
    while (j + 1< arr.size()) {
        cur += arr[j];
        if (cur == 2 * sum)
            return true;
        j++;
    }

    return false;
}

int main() {
    vector<int> arr {1,-1,1,-1};
    cout << canThreePartsEqualSum(arr) << endl;

    return 0;
}
