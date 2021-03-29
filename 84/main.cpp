#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int ans = 0;
    vector<int> left(heights.size()); //第i个矩形左边第一个高度小于它的矩形的索引
    vector<int> right(heights.size());//第i个矩形右边第一个高度小于它的矩形的索引

    stack<int> monstk;

    for (int i = 0; i < heights.size(); i++) {
        while (!monstk.empty() && heights[monstk.top()] >= heights[i])
            monstk.pop();
        left[i] = monstk.empty() ? -1 : monstk.top();
        monstk.push(i);
    }

    while (!monstk.empty())
        monstk.pop();


    for (int i = heights.size() - 1; i >= 0; i--) {
        while (!monstk.empty() && heights[monstk.top()] >= heights[i])
            monstk.pop();
        right[i] = monstk.empty() ? heights.size() : monstk.top();
        monstk.push(i);
    }

    for (int i = 0; i < heights.size(); i++) {
        ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        cout << left[i] << '-' << right[i] << endl;
    }

    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
