#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> largeGroupPositions(string s) {
    vector<vector<int>> ans;
    int start = 0, end = 0;
    while (start < s.size()) {
//       二分法找到end
        int l = start, r = s.size() - 1;
        while (l < r) {
        }


        ans.push_back({start, end});
        start = end + 1;
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
