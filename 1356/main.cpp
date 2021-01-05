#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countBits(int num) {
    int count=0;
    while(num) {
        if (num & 1)
            count++;
        num >>= 1;
    }
    return count;
}


vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [](int a, int b) {
        return countBits(a) < countBits(b) || (countBits(a) == countBits(b) && a < b);
    });
    for(auto& i: arr)
        cout <<i <<' ';

    return arr;
}

int main() {
    vector<int> arr{1111,7644,1107,6978,8742,1,7403,7694,9193,4401,377,8641,5311,624,3554,6631};
    sortByBits(arr);
    return 0;
}
