#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()|| target>matrix[matrix.size()-1][matrix[0].size()-1]
    || target< matrix[0][0])
        return false;
    int idx = matrix[0].size()/2;

    int l = 0, r = matrix.size();
//    二分
    while (r >l+1) {
        int mid = (r + l) >> 1;
        if (matrix[mid][idx] <= target)
            l = mid;
        else
            r = mid;
    }
    vector<int>num;
    if (matrix[l][idx] <= target) {
        for (int i = idx; i < matrix[0].size(); i++)
            num.push_back(matrix[l][i]);
        if (l<matrix.size()-1) {
            for (int i = 0; i < idx; i++)
                num.push_back(matrix[l + 1][i]);
        }
    }
    else {
        for (int i = 0; i < idx; i++)
            num.push_back(matrix[l][i]);
    }

//    二分
    l = 0;
    r = num.size();
    while (l + 1 < r) {
        int mid = (l+r)>>1;
        if (num[mid] > target)
            r = mid;
        else l = mid;
    }

    return num[l] == target;
}

int main() {
//    vector<int>num={1,2,3,4, 8};
//
//    int l = 0;
//    int r = num.size();
//    while (l + 1 < r) {
//        int mid = (l+r)>>1;
//        if (num[mid] > 0)
//            r = mid;
//        else l = mid;
//    }
//    cout << num[l];
vector<vector<int>>matrix={{1,3,5,7},
                           {10, 11, 16, 20},
                           {23, 30, 34, 50}};
cout<<searchMatrix(matrix, 61);

    return 0;
}
