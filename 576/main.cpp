#include <iostream>
#include <map>
#include <vector>
using namespace std;


int dir[4][2] = {{0,1}, {1, 0}, {0,-1},{-1,0}};
long mod = 1e9+7;

map<pair<int, int>, int> ma;
int dfs(int m, int n, int k, int i, int j) {
    if (!ma.count(make_pair(i * m + j, k))) {
        if (i < 0 || j < 0 || i >= m || j >= n)
            ma[make_pair(i * m + j, k)] = 1;
        else if (k > 0)
            for (auto &d: dir) {
                int a = i + d[0];
                int b = j + d[1];
                ma[make_pair(i * m + j, k)] += dfs(m, n, k - 1, a, b);
                ma[make_pair(i * m + j, k)] %= mod;
            }
    }

    return ma[make_pair(i * m + j, k)];
}

int findPaths(int m, int n, int N, int i, int j) {
    ma.clear();
    return dfs(m, n, N, i, j);
}

int main() {
    std::cout << findPaths(1,3,2,0,0) << std::endl;
    return 0;
}
