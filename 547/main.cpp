#include <iostream>
#include <vector>
using namespace std;
/*
vector<int> ranks;
vector<int> father;

void init(int N) {
    ranks.clear();
    ranks.resize(N, 0);
    father.clear();
    father.resize(N);
    for (int i = 0; i < N; i++)
        father[i] = i;
}

int findFather(int x) {
    if (x != father[x]) {
        father[x] = findFather(father[x]);
    }
    return father[x];
}

bool isSame(int a, int b) {
    return findFather(a) == findFather(b);
}

void unite(int a, int b) {
    a = findFather(a);
    b = findFather(b);

    if (ranks[a] < ranks[b])
        father[a] = b;
    else {
        father[b] = a;
        if (ranks[a] == ranks[b])
            ranks[a]++;
    }
}


int findCircleNum(vector<vector<int>>& M) {
    init(M.size());

    for (int i = 0; i < M.size(); i++)
        for (int j = 0; j < M[0].size(); j++)
            if (M[i][j]) {
                unite(i, j);
            }
    int ans = 0;
    for (int i = 0; i < M.size(); i++)
        if (i == father[i])
            ans++;
    return ans;
}
*/

void dfs(vector<vector<int>>& M, int idx, vector<int>& visited) {
    for (int i = 0; i < M[idx].size(); i++)
        if (M[idx][i] && !visited[i]) {
            dfs(M, i, visited);
        }
}

int findCircleNum(vector<vector<int>>& M) {
    vector<int> visited(M.size());
    int ans = 0;

    for (int i = 0; i < M.size(); i++)
        if (!visited[i]) {
            ans++;
            dfs(M, i, visited);
        }

    return ans;
}

int main() {
    return 0;
}
