#include <iostream>
#include <set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int l = 0, r = 0;
    set<char> st;
    int maxL =0;
    int x, y;

    while (r < s.size()) {
        if (!st.count(s[r])) {
            st.insert(s[r]);
            r++;
        }
        else {
//            maxL = max(maxL, (int) st.size());
            if (maxL < st.size())
            {
                maxL = st.size();
                x = l;
                y = r;
            }
            while (l < r && s[l] != s[r]) {
                st.erase(s[l]);
                l++;
            }
            r++;
            l++;
        }
    }
    if (maxL < st.size())
    {
        maxL = st.size();
        x = l;
        y = r;
    }
    cout << x <<' ' << y << ' ' << maxL;
    return maxL;
}

int main() {
    lengthOfLongestSubstring("p");
    return 0;
}
