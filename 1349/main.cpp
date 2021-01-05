#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Edge{
    int to, cap, rev;
    Edge(int t, int c, int r): to(t), cap(c), rev(r){}
};

vector<bool> used;
//vector<vector<Edge>> G;
vector<vector<int>> G;
vector<int>match;
bool isNear(pair<int, int>x, pair<int,int>y) {
    if ((x.first == y.first || abs(x.first - y.first) == 1) && abs(x.second - y.second) == 1)
        return true;
    return false;
}
/*
void addEdge(int from, int to, int cap) {
    G[from].push_back(Edge(to, cap, G[to].size()));
    G[to].push_back(Edge(from, 0, G[from].size()-1));
}


int dfs(int s, int t, int f) {
    if (s == t)
        return f;
    else {
        used[s] = true;
        for (auto& edge: G[s]){
            if (!used[edge.to] && edge.cap > 0) {
                int d = dfs(edge.to, t, min(f, edge.cap));
                if (d > 0) {
                    edge.cap -= d;
                    G[edge.to][edge.rev].cap += d;
                    return d;
                }
            }
        }
    }
    return 0;
}

int maxStudents(vector<vector<char>>& seats) {
    vector<pair<int, int>> nodes;
    set<int>count;
    int flow=0;
//    记录位置
    for (int i = 0; i < seats.size(); i++)
        for (int j = 0; j < seats[0].size(); j++) {
            if (seats[i][j] == '.')
                nodes.emplace_back(i, j);
        }
//    添加边
G.clear();
G.resize(2*nodes.size() + 2);
used.resize(2*nodes.size()+2);
    for (int i = 0; i < nodes.size(); i++)
        for (int j = i + 1; j < nodes.size(); j++) {
            if (!isNear(nodes[i], nodes[j])) {
                addEdge(i + 1, j + 1 + nodes.size(), 1);
                addEdge(j + 1, i + 1 + nodes.size(), 1);
            }
        }
//    添加从原点到第一层的边
    for (int i = 0; i < nodes.size(); i++)
        addEdge(0, i + 1, nodes.size());
//    添加从第二层到汇点的边
    for (int i = 0; i < nodes.size(); i++)
        addEdge(i + 1 + nodes.size(), 2 * nodes.size() + 1, nodes.size());

    for (;;) {
        used.assign(used.size(), false);
        int f = dfs(0, 2 * nodes.size() + 1, INT16_MAX);
        if (f == 0)
            break;
        flow += f;
    }
    for (int i = 1; i <= nodes.size(); i++) {
        for (auto & edge: G[i])
            if (edge.cap == 0)
                count.insert(edge.to);
    }
    cout << count.size();
    return flow;
}
*/

bool dfs(int v) {
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++){
        int u = G[v][i];
        int w = match[u];
        if (w < 0 || !used[w] && dfs(w)) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int maxStudents(vector<vector<char>>& seats) {
    vector<pair<int, int>> nodes;
//    记录位置
    for (int i = 0; i < seats.size(); i++)
        for (int j = 0; j < seats[0].size(); j++) {
            if (seats[i][j] == '.')
                nodes.emplace_back(i, j);
        }
//    添加边
    G.clear();
    match.clear();
    used.clear();
    G.resize(nodes.size());
    match.resize(nodes.size(), -1);
    used.resize(nodes.size(), false);
    for (int i = 0; i < nodes.size(); i++)
        for (int j = i + 1; j < nodes.size(); j++) {
            if (isNear(nodes[i], nodes[j])) {
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    int res = 0;
        for (int v = 0; v < nodes.size(); v++) {
            if (match[v] == -1) {
                used.assign(used.size(), false);
                if (dfs(v))
                    res++;
            }
        }
        return nodes.size()-res;
}



int main() {
    vector<vector<char>> seats = {{'#','.','#','#','.','#'},
                                  {'.','#','#','#','#','.'},
                                  {'#','.','#','#','.','#'}};


    std::cout << maxStudents(seats) << std::endl;
    return 0;
}
