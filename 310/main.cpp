#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> degree;
vector<int>ans;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    ans.clear();
    degree.clear();
    degree.resize(n, 0);
    vector<vector<int>> G(n);
//    初始化图
    for (auto &edge: edges) {
        degree[edge[0]]++;
        degree[edge[1]]++;
        G[edge[0]].push_back(edge[1]);
        G[edge[1]].push_back(edge[0]);
    }

//    从叶子开始广度优先遍历
    queue<int> que;
    for (int i = 0; i < n; i++)
        if (degree[i] == 1) {
            que.push(i);
        }
//        一层层剥去叶子 最后是结果

        while(!que.empty()) {
            ans.clear();
            int size = que.size();
            while (size--) {
                int temp = que.front();
                que.pop();
                ans.push_back(temp);
                for (auto& node: G[temp]) {
                    degree[node]--;
                    if (degree[node] == 1) {
                        que.push(node);
                    }
                }
            }
        }
//    找到最后一层
    return ans;
}

int main() {
    vector<vector<int>> edges={{0, 1}, {1,2},{1,3},{2,4},{3,5},{4,6}};
    findMinHeightTrees(7,edges);
    for (auto& i: ans)
        cout <<i<< ' ';
    return 0;
}
