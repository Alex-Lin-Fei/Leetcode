#include <iostream>
#include <vector>
using namespace std;


//dfs超时
void dfs(int& n, int cur, int& dst, int k, int cost, int& ans, vector<vector<int>>mp) {
    if (cur == dst) {
        ans = min(ans, cost);
        return;
    }
    else if (!k)
        return;
    else {
        for (int i = 0; i < n; i++) {
            if (mp[cur][i] != INT16_MAX && mp[cur][i] + cost < ans) {
                dfs(n, i, dst, k-1, cost + mp[cur][i], ans, mp);
            }
        }
    }
}

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    int ans = INT16_MAX;
    vector<vector<int>>mp(n, vector<int>(n, INT16_MAX));
    for (auto & flight : flights)
        mp[flight[0]][flight[1]] = flight[2];
    dfs(n, src, dst, K+1, 0, ans, mp);
    return (ans == INT16_MAX)? -1: ans;
}

//Bellman-Ford算法
int findCheapestPrice1(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    vector<int> dist(n, INT16_MAX);
    dist[src] = 0;

//    for (auto &f: flights)
//        if (f[0] == src)
//            dist[f[1]] = f[2];

    while (K >= 0) {
        vector<int>dp = dist;
        for (auto &f: flights)
            dp[f[1]] = min(dp[f[1]], dist[f[0]] + f[2]);
        K--;
        swap(dp, dist);
    }
    return (dist[dst] == INT16_MAX) ? -1 : dist[dst];
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>> flights;
    for (int i = 0; i < 3; i++) {
        vector<int>l;
        flights.push_back(l);
        for (int j = 0; j < 3; j++) {
            int x;
            cin >> x;
            flights[i].push_back(x);
        }
    }
    int src, dst, k;
    cin >> src >> dst >> k;
    std::cout << findCheapestPrice1(n, flights, src, dst, k) << std::endl;
    return 0;
}
