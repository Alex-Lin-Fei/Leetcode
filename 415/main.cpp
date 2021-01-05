#include <iostream>
#include <algorithm>

using namespace std;

string addStrings(string num1, string num2) {
    string ans;

    int r1 = num1.size() - 1;
    int r2 = num2.size()-1;
    int c = 0;
    int res = 0;
    while (r1 >= 0 && r2 >= 0){
        res = num1[r1]-'0' + num2[r2] - '0' + c;
        c = res /10;
        res %= 10;
        ans += '0'+res;
        r1--;
        r2--;
    }

    while (r1>=0){
        res = c + num1[r1] - '0';
        c = res / 10;
        res %=10;
        ans += '0' + res;
        r1--;
    }

    while (r2>=0){
        res = c + num2[r2] - '0';
        c = res / 10;
        res %=10;
        ans += '0' + res;
        r2--;
    }

    ans += '0' + c;

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {

    std::cout << addStrings("1", "9") << std::endl;
    return 0;
}
