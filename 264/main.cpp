#include <iostream>
#include <set>
#include <queue>

using namespace std;

int nthUglyNumber(int n) {
     set<int>once; //去重
     priority_queue<int, vector<int>, greater<>> uglyNumber;
     int factors[] = {2,3,5};
int ans = 1;

     uglyNumber.push(1);
     once.insert(1);

    while (n--) {
        ans = uglyNumber.top();
        uglyNumber.pop();

        for (auto &factor: factors) {
            if (!once.count(factor * ans)) {
                once.insert(factor * ans);
                uglyNumber.push(factor * ans);
            }
        }
    }

    return ans;
}

int main() {

        std::cout << nthUglyNumber(19) << std::endl;

    return 0;
}
