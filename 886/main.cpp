#include <iostream>
#include <vector>
using namespace std;


const int MAX_V = 2000;

vector<int> G[MAX_V];
vector<int> color;

void addEdge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

bool dfs(int v, int c) {
    color[v] = c;
    for (int i = 0; i < G[v].size(); i++) {
        int u = G[v][i];
        if (color[v] == color[u] || color[u] == -1 && !dfs(u, (c+1)%2))
            return false;
    }
    return true;
}

bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
//    连边
color.resize(N, -1);
     for (auto& g: dislikes)
         addEdge(g[0]-1, g[1]-1);
     for (int i = 0; i < N; i++) {
         if (color[i] < 0){
             if (!dfs(i, 0))
                 return false;
         }
     }
     return true;
}


int main() {
    vector<vector<int>>v = {{1,2}, {3,4}, {4,5}, {3,5}};

    std::cout << possibleBipartition(5, v)<< std::endl;
    return 0;
}
