#include <iostream>
#include <vector>
using namespace std;

int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
    vector<int>dp(books.size());
    dp[0] = books[0][1];
    for (int i = 1; i < dp.size(); i++)
        dp[i] = INT16_MAX;
    for (int i = 1; i < books.size(); i++) {
        int width = books[i][0], j = i-1, h = books[i][1];
        dp[i] = dp[i-1]+h;
        while (j >= 0) {
            if (width + books[j][0] > shelf_width)
                break;
            width += books[j][0];
            h = max(h, books[j][1]);
            if (j > 0)
                dp[i] = min(dp[i], dp[j-1] + h);
            else
                dp[i] = min(dp[i], h);
            j--;
        }
    }
    for (auto& i: dp)
        cout << i << ' ';

    return dp[books.size() - 1];
}

int main() {
    vector<vector<int>>h;
    int x = 3;
    for (int i = 0; i < x; i++) {
        vector<int> l;
        int a;
        int b;
        cin >> a;
        cin >> b;
        h.push_back(l);
        h[i].push_back(a);
        h[i].push_back(b);
    }
    std::cout << minHeightShelves(h, 6) << std::endl;
    return 0;
}
