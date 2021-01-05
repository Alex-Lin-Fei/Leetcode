#include <iostream>
#include <random>
#include <vector>
#include <functional>

using namespace std;

int partition(vector<int>& arr, int l, int r) {
    default_random_engine re{};
    uniform_int_distribution<> dist{l, r};
    auto die = bind(dist, re);
    int idx = die();

    swap(arr[r], arr[idx]);
    int x = arr[r];

    int i = l - 1;
    int j = l;
    while (j < r) {
        if (arr[j] <= x) {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i], arr[r]);
    return i;
}

void func(vector<int>& arr, int l, int r, int k) {
    if (l >= r)
        return;
    int pos = partition(arr, l, r);
    if (pos == k)
        return;
    else if (pos < k)
        func(arr, pos + 1, r, k);
    else
        func(arr, l, pos - 1, k);
}

vector<int> getLeastNumbers(vector<int>& arr, int k) {
    vector<int> ans;

    func(arr, 0, arr.size() - 1, k);
    ans.reserve(k);
    for (int i = 0; i < k; i++)
        ans.push_back(arr[i]);

    return ans;
}

int main() {
    vector<int> v{3,2,1};
    getLeastNumbers(v, 2);
    return 0;
}
