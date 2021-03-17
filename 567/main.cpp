#include <iostream>
#include <vector>
using namespace std;


//overtime
/*

bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length())
        return false;

    sort(s1.begin(), s1.end());

    for (int i = 0; i <= s2.length()-s1.length(); i++) {
        string str = s2.substr(i, s1.length());
        sort(str.begin(), str.end());
        if (str == s1)
            return true;
    }
    return false;
}
 */

bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length())
        return false;

    vector<int> count1(26), count2(26);

    for (int i = 0; i < s1.length(); i++) {
        count1[s1[i] - 'a']++;
        count2[s2[i] - 'a']++;
    }

    if (count1 == count2)
        return true;

    for (int i = s1.length(); i < s2.length(); i++) {
        count2[s2[i] - 'a']++;
        count2[s2[i - s1.length()] - 'a']--;
        if (count1 == count2)
            return true;
    }
    return false;
}


int main() {
    vector<int> a(1), b(1);
    a[0] = b[0] = 0;
    cout << (a==b)<<endl;


    std::cout << checkInclusion("dad", "eiboaxaddoo") << std::endl;
    return 0;
}
