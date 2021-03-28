#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int maxArea(vector<int>& height) {
    int ans = 0;

    vector<int> left;  //从左往右压入的单调递增栈
    vector<int> right; //从右往右压入的单调递增栈

    left.push_back(0);
    right.push_back(height.size() - 1);

    for (int i = 0; i < height.size(); i++) {
        if (height[i] > height[left.back()])
            left.push_back(i);
    }

    for (int i = height.size() - 1; i >= 0; i--) {
        if (height[i] > height[right.back()])
            right.push_back(i);
    }
    reverse(left.begin(), left.end());
    reverse(right.begin(), right.end());

    while (!left.empty() && !right.empty() && left.back() < right.back()) {
        ans = max(ans, min(height[left.back()], height[right.back()]) * (right.back() - left.back()));
        if (height[left.back()] < height[right.back()])
            left.pop_back();
        else
            right.pop_back();
    }

    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
