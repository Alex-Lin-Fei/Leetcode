#include <iostream>
#include <vector>
using namespace std;



bool dfs(int v, int c, vector<vector<int>>& graph, vector<int> & color) {
    color[v] = c;
    for (int i = 0; i < graph[v].size(); i++)
        if (color[graph[v][i]] == c)
            return false;
        else if (color[graph[v][i]] == 0 && !dfs(graph[v][i], -c, graph, color))
            return false;
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    vector<int> color;
    color.resize(graph.size());
    for (int i = 0; i < graph.size(); i++)
        if (!color[i]) {
            if (!dfs(i, 1, graph, color))
                return false;
        }
    return true;
}

int main() {

    return 0;
}
