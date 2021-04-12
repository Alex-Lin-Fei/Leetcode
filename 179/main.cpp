#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [&](int a, int b) {
       string s1 = to_string(a);
       string s2 = to_string(b);

       if (s1.length() == s2.length())
           return s1 > s2;
       else {
           bool hasSwapped = false;
           bool aPre = false;
           if (s1.length() < s2.length()) {
               swap(s1, s2);
               hasSwapped = true;
           }

           string sub1 = s1.substr(0, s2.length());

           if (sub1 > s2)
               aPre = true;
           else if (sub1 == s2) {
               string sub2 = s1.substr(s2.length(), s1.length() - s2.length());
               string s3 = sub2 + sub1;
               if (s3 > s1)
                   aPre = true;
           }

           return (aPre && !hasSwapped) || (!aPre && hasSwapped);
       }
    });

    string ans;
    for (auto& num: nums) {
        cout << num<<endl;
        ans += to_string(num);
    }

    return ans;
}


int main() {
vector<int> nums{0, 0};

cout << largestNumber(nums);
    return 0;
}
