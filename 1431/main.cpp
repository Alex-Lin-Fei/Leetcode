#include <iostream>
#include <vector>
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> ans(candies.size());
    int maxNum = candies[0];
    for (int i = 1; i < candies.size(); i++) {
        maxNum = max(maxNum, candies[i]);
    }
    for (int i = 0; i < ans.size(); i++) {
        if (maxNum - candies[i] <= extraCandies)
            ans[i] = true;
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
