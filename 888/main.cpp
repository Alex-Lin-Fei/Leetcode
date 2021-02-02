#include <iostream>
#include <vector>
#include <numeric>
#include <set>
#include <cassert>

using namespace std;

vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    int delta = accumulate(A.begin(), A.end(), 0) - accumulate(B.begin(), B.end(), 0);
    delta /= 2;
    set<int> sA;

    for (auto &item: A)
        sA.insert(item - delta);
    for (auto &item : B)
        if (sA.count(item))
            return {item + delta, item};

    return {};
}

int main() {
    vector<int> A{1,2,5}, B{2,4};
    vector<int> ans = fairCandySwap(A,B);
    std::cout << ans[0] << ans[1] << std::endl;
    return 0;
}
