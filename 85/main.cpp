#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int getLargestRect(vector<int> & v) {
    int maxv = 0;
    v.push_back(0);
    stack<pair<int, int>> s;

    for (int i = 0; i < v.size(); i++) {
        if (s.empty() || s.top().first < v[i])
            s.push(make_pair(v[i], i));
        else if (s.top().first > v[i]) {
            int target = i;
            while (!s.empty() && s.top().first >= v[i]) {
                auto pre = s.top();
                s.pop();
                int area = pre.first * (i - pre.second);
                maxv = max(maxv, area);
                target = pre.second;
            }
            s.push(make_pair(v[i], target));
        }
    }
    return maxv;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    vector<vector<int>> T(matrix.size(), vector<int>(matrix[0].size()));
    for (int j = 0; j < matrix[0].size(); j++)
        for (int i = 0; i < matrix.size(); i++) {
            if (!(matrix[i][j])-'0')
                T[i][j] = 0;
            else
                T[i][j] = (i > 0) ? T[i - 1][j] + 1 : 1;
        }
    int maxv = 0;
    for (int i = 0; i < matrix.size(); i++)
        maxv = max(maxv, getLargestRect(T[i]));

    return maxv;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
