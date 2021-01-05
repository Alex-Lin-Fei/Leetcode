#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> largeGroupPositions(string s) {
    vector<vector<int>> ans;
    int start = 0, end = 0;
    while (start < s.size()) {
//       二分法找到end
        int l = start + 1, r = s.size() - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (s[m] == s[start])
                l = m + 1;
            else
                r = m - 1;
        }
        end = l - 1;
        ans.push_back({start, end});
        start = end + 1;
    }

    for (auto &item: ans)
        cout << item[0] << ' ' << item[1] << endl;

    return ans;
}

int main() {

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
