#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
    vector<int> leave(customers.size());
    int temp = 0;
    int ans = 0;

    for (int i = 0; i < leave.size(); i++)
        leave[i] = customers[i] * grumpy[i];

    for (int i = 0; i < X; i++) {
        temp += leave[i];
    }
    ans = temp;

    for (int i = X; i < leave.size(); i++) {
        temp += leave[i] - leave[i - X];
        ans = max(ans, temp);
    }

    return accumulate(customers.begin(), customers.end(), 0) -
           accumulate(leave.begin(), leave.end(), 0) + ans;
}

int main() {
    vector<int> customers = {1,0,1,2,1,1,7,5};
    vector<int> grumpy = {0,1,0,1,0,1,0,1};

    std::cout << maxSatisfied(customers, grumpy, 3) << std::endl;
    return 0;
}
