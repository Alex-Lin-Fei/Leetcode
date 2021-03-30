#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
//    判断是否target小于最小元素或大于最大元素
    if (target < matrix[0][0] || target > matrix.back().back())
        return false;
//    判断target是否小于第一行中间元素
    else if (target < matrix[0][matrix[0].size() / 2]) {
        int l = 0, r = matrix[0].size() / 2 - 1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (matrix[0][mid] < target)
                l = mid + 1;
            else if (matrix[0][mid] > target)
                r = mid - 1;
            else
                return true;
        }
    }

//    判断target是否大于最后一行中间元素

    else if (target > matrix.back()[matrix[0].size() / 2]) {
        int l = matrix[0].size() / 2 + 1, r = matrix[0].size() - 1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (matrix.back()[mid] < target)
                l = mid + 1;
            else if (matrix.back()[mid] > target)
                r = mid - 1;
            else
                return true;
        }
    }

//    判断target是否在矩阵中
    else {
//        找出最后一个中间元素不大于target的row
        int l = 0, r = matrix.size();

        while (l < r - 1) {
            int mid = (r - l) / 2 + l;
            if (matrix[mid][matrix[0].size() / 2] <= target)
                l = mid;
            else
                r = mid;
        }
//cout << " l: " << l << endl;
        if (matrix[l][matrix[0].size() / 2] == target)
            return true;
        else {
            int left = l * matrix[0].size() + matrix[0].size() / 2;
//        找出第一个中间元素不小于target的row
            l = -1, r = matrix.size() - 1;
            while (l < r - 1) {
                int mid = (r - l) / 2 + l;
                if (matrix[mid][matrix[0].size() / 2] >= target)
                    r = mid;
                else
                    l = mid;
            }
//            cout << " r: " << r << endl;

            if (matrix[r][matrix[0].size() / 2] == target)
                return true;
            else {
                int right = r * matrix[0].size() + matrix[0].size() / 2;

                while (left <= right) {
                    int mid = (right - left) / 2 + left;
//                    cout << matrix[mid / matrix[0].size()][mid % matrix[0].size()]<<endl;
                    int res = matrix[mid / matrix[0].size()][mid % matrix[0].size()] - target;
                    if (res > 0)
                        right = mid-1;
                    else if (res < 0)
                        left = mid+1;
                    else
                        return true;
                }
            }
        }
    }

    return false;
}

int main() {
    vector<vector<int>> matrix = {{1,  3,  5,  7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 50}};
    for (auto &row : matrix) {
        for (auto &i: row)
            cout << searchMatrix(matrix, i) << ' ';
        cout << endl;
    }

    return 0;
}
