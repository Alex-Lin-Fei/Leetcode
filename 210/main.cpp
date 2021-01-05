#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

//const int N = 1e5+1;
//queue<int> q;
//vector<int> ans;
//bool visit[N];
//int indeg[N];
//int cnt;
//
//void bfs(int s, vector<int> G[]) {
//    q.push(s);
//    visit[s] = true;
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        cnt++;
//        ans.push_back(u);
//        for (int & i : G[u]) {
//            --indeg[i];
//            if (!indeg[i]) {
//                visit[i] = true;
//                q.push(i);
//            }
//        }
//    }
//}
//
//
//vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//    vector<int> G[numCourses];
//    bool invalid = false;
//    for (auto &prerequisite : prerequisites) {
//        indeg[prerequisite[0]]++;
//        G[prerequisite[1]].push_back(prerequisite[0]);
//    }
//    for (int i = 0; i < numCourses; i++)
//        if (!visit[i] && !indeg[i])
//            bfs(i, G);
//    for (int i = 0; i < numCourses; i++)
//        if (!visit[i]) {
//            invalid = true;
//            break;
//        }
//    if (cnt != numCourses)
//        invalid = true;
//    if (invalid)
//        ans.clear();
//    return ans;
//}

vector<int> visited;
vector<vector<int>> edges;
vector<int> res;
bool invalid;

void dfs(int s) {
    visited[s] = 1;
    for (auto& v: edges[s]) {
        if (!visited[v])
        {
            dfs(v);
            if (invalid)
                return;
        }
        else if (visited[v] == 1) {
            invalid = true;
            return;
        }
    }
    visited[s] = 2;
    res.push_back(s);
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    edges.resize(numCourses);
    visited.resize(numCourses);
    for (auto& prerequisite: prerequisites){
        edges[prerequisite[1]].push_back(prerequisite[0]);
    }
    for (int i = 0; i < numCourses && invalid; i++) {
        if (!visited[i])
            dfs(i);
    }
    if (invalid)
        return {};
    reverse(res.begin(), res.end());
    return res;
}


int main() {
    vector<vector<int>> p;
//    for (int i = 0; i < 1; i++) {
//        vector<int> l;
//        p.push_back(l);
//        for (int j = 0; j < 2; j++) {
//            int a;
//            cin >> a;
//            p[i].push_back(a);
//        }
//    }
    for (auto& i: findOrder(1, p))
        cout << i;

    return 0;
}
