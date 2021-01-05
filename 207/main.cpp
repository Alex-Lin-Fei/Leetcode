#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 1e5+1;

queue<int> q;
bool visit[N];
int indeg[N];
int cnt;

void bfs(int s, vector<int> G[]) {
    q.push(s);
    visit[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;
        for (int & i : G[u]) {
            --indeg[i];
            if (!indeg[i]) {
                visit[i] = true;
                q.push(i);
            }
        }
    }
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> G[numCourses];
    for (auto &prerequisite : prerequisites) {
        indeg[prerequisite[0]]++;
        G[prerequisite[1]].push_back(prerequisite[0]);
    }
    for (int i = 0; i < numCourses; i++)
        if (!visit[i] && !indeg[i])
            bfs(i, G);
    for (int i = 0; i < numCourses; i++)
        if (!visit[i])
            return false;
    return (cnt == numCourses);
}

int main() {
    vector<vector<int>> p;
    for (int i = 0; i < 1; i++) {
        vector<int> l;
        p.push_back(l);
        for (int j = 0; j < 2; j++) {
            int a;
            cin >> a;
            p[i].push_back(a);
        }
    }

    std::cout << canFinish(2, p) << std::endl;
    return 0;
}
