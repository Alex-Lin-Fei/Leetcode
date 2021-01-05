#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> times;


int INF = 101;
int dfs(int x, vector<bool>& visit, vector<vector<int>>& times) {
    int f = 0;
    visit[x] = true;
    for (int i = 0; i < times.size(); i++) {
        if (times[i][0] == x && !visit[times[i][1]]) {
            visit[times[i][1]] = true;
            f = max(dfs(times[i][1], visit, times) + times[i][2], f);
        }
    }
    return f;
}



int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<bool> visit;
    visit.resize(N + 1);
//    int l = dfs(K, visit, times);
//    for (int i = 1; i < visit.size(); i++)
//        if (!visit[i])
//            return -1;
//    return l;
    vector<int> dist;
    dist.resize(N + 1);
    for (int i = 1; i < dist.size(); i++)
        dist[i] = INF;
    dist[K] = 0;
    visit[K] = true;
    for (auto &time : times)
        if (time[0] == K) {
            dist[time[1]] = time[2];
        }
    int num = 1;
    int shorts;
    int u;
    while (num < N) {
        shorts = INF;
        u = K;
        for (int i = 1; i < dist.size(); i++) {
            if (shorts > dist[i] && !visit[i]) {
                shorts = dist[i];
                u = i;
            }
        }
        if (shorts == INF)
            return -1;
        visit[u] = true;
        if (num == N - 1)
            break;
        for (auto & time : times)
            if (time[0] == u && dist[time[1]] > dist[u] + time[2])
                dist[time[1]] = dist[u] + time[2];
        num++;
    }

    return shorts;

}

int main() {
    int N = 3;
    int M = 3;
    for (int i = 0; i < N; i++) {
        vector<int> line;
        times.push_back(line);
        for (int j = 0; j < M; j++) {
            int n;
            cin >> n;
            times[i].push_back(n);
        }
    }
    cout << networkDelayTime(times, 3, 1);

    return 0;
}
