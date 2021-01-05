#include <iostream>
#include <vector>
using namespace std;

int hIndex(vector<int>& citations) {
    if (citations.empty())
        return 0;

    int l = 0;
    int r = citations.size();

    while (l < r) {
        int mid = (l + r) >> 1;
        if (citations[mid] >= citations.size() - mid)
            r = mid;
        else
            l = mid+1;
    }
    return citations.size() - r;
}

int main() {
    vector<int> v={0, 1, 3, 5, 6};
    cout << hIndex(v);

    return 0;
}
