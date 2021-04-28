#include <iostream>
#include <vector>
using namespace std;


//dp
int numDecodings(string s) {
    vector<int> dp(s.size() + 1);

    dp[0] = 1;
    for (int i = 1; i <= s.length(); i++) {
        if (s[i-1] == '0')
            dp[i] = dp[i-2];
        else {
            if (i == 1)
                dp[i] = dp[i-1];
            else {
                
            }
        }

    }


    return dp.back();
}

int main() {

    std::cout << numDecodings("123") << std::endl;
    return 0;
}
