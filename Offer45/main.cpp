#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int& a, int& b) {
    string stra = to_string(a);
    string strb = to_string(b);
    string strab = stra + strb;
    string strba = strb + stra;
    for (int i = 0; i < strab.size(); i++)
        if (strab[i] - '0'< strba[i] - '0')
            return true;
        else if (strab[i]  -'0'> strba[i] -'0')
            return false;
    return true;
}

string minNumber(vector<int>& nums) {
    string ans;
//    sort(nums.begin(), nums.end(), cmp);
//    for (auto num: nums) {
//        ans += to_string(num);
//        cout << num<< ' ';
//    }
//    return ans;
    vector<string> strs;
    for (auto &num: nums)
        strs.push_back(to_string(num));
    sort(strs.begin(), strs.end(), [&](string &a, string &b) {
        return a + b < b + a;
    });
    for (auto& str: strs)
        ans += str;
    return ans;
}

int main() {
    vector<int> v{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cout << minNumber(v);
}
