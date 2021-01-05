#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int heightChecker(vector<int>& heights) {
    vector<int> s = heights;
    sort(s.begin(), s.end());
    int sum = 0;
    int i = 0;
    while (i < heights.size()) {
        if (s[i] != heights[i])
            sum++;
        i++;
    }
    return sum;
}

int main() {
    vector<int> h;
    h.push_back(1);
    h.push_back(1);
    h.push_back(4);
    h.push_back(2);
    h.push_back(1);
    h.push_back(3);

    std::cout << heightChecker(h) << std::endl;
    return 0;
}
