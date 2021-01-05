#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
    vector<vector<int>> dist = vector<vector<int>>(N, vector<int>(N, INT32_MAX));

    for (auto &edge: edges)
        dist[edge[0]][edge[1]] = dist[edge[1]][edge[0]] = 1;
    for (int i = 0; i < N; i++)
        dist[i][i] = 0;

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (dist[i][k] < INT32_MAX && dist[k][j] < INT32_MAX)
                    dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++)
//            cout << dist[i][j] << ' ';
//        cout << endl;
//    }
    vector<int> ans = vector<int>(N);
    for (int i = 0; i < N; i++)
        ans[i] = accumulate(dist[i].begin(), dist[i].end(), 0);
//        for (int j = 0; j < N; j++)
//            ans[i] += dist[i][j];
    for (auto &i: ans)
        cout << i << ' ';
    return ans;
}

int main() {
    vector<vector<int>> v={{0,1}, {0,2}, {2,3}, {2,4}, {2,5}};
    sumOfDistancesInTree(6, v);

    return 0;
}
