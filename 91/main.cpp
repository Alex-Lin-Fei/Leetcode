#include <iostream>
#include <vector>
using namespace std;


//dp
int numDecodings(string s) {
    vector<int> dp(s.size() + 1);

    dp[0] = 1;
    for (int i = 1; i <= s.length(); i++) {
        if (s[i-1] == '0') {
            if (i >= 2 && (s[i - 2] == '1' || s[i - 2] == '2'))
                dp[i] = dp[i - 2];
            else
                return 0;
        }
        else {
            if (i == 1 || s[i-2] > '2' || s[i-2] == '0' || (s[i-2] == '2' && s[i-1] > '6'))
                dp[i] = dp[i-1];
            else {
                dp[i] = dp[i-1] + dp[i-2];
            }
        }
    }

    return dp.back();
}

int main() {

    std::cout << numDecodings("60") << std::endl;
    return 0;
}
