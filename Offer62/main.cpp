#include <iostream>
#include <vector>
using namespace std;

//over time
//int lastRemaining(int n, int m) {
//    vector<int> arr;
//    auto idx = 0;
//
//    arr.reserve(n);
//for (int i = 0; i < n; i++)
//        arr.push_back(i);
//
//    while (arr.size() > 1) {
//        idx = (idx + m - 1) % arr.size();
//        arr.erase(arr.begin() + idx);
//    }
//
//    return arr[0];
//}


int lastRemaining(int n, int m) {
    if (n == 0)
        return 0;
    else
        return (lastRemaining(n - 1, m) + m) % n;
}

int main() {
    std::cout << lastRemaining(5,3) << std::endl;
    return 0;
}
