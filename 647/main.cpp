#include <iostream>
#include <vector>
using namespace std;

double medianNum(vector<int>& v, int l, int r) {
    if ((l + r) % 2)
        return 1.0 * (v[(l + r)/2] + v[(l+r)/2+1])/2;
    else
        return v[(l+r)/2];
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int l1 = 0, r1 = nums1.size() - 1;
    int l2 = 0, r2 = nums2.size() - 1;
    double m1, m2;
    while (l1 <= r1 && l2 <= r2) {
        m1 = medianNum(nums1, l1, r1);
        m2 = medianNum(nums2, l2, r2);
        cout << m1 << ' ' << m2 << endl;
        if (m1 < m2) {
            l1 = (l1 + r1) / 2 + 1;
            r2 = (l2 + r2 - 1) / 2;
        } else if (m1 > m2) {
            l2 = (l2 + r2) / 2 + 1;
            r1 = (l1 + r1 - 1) / 2;
        } else if (m1 == m2) {
            return m1;
        }
    }
    return (m1 + m2) / 2;
}

int main() {
    vector<int>v1;
    vector<int>v2;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(5);
    v2.push_back(3);
    v2.push_back(4);
    std::cout << findMedianSortedArrays(v1, v2) << std::endl;
    return 0;
}
