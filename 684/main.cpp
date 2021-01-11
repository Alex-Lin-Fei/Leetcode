#include <iostream>
#include <vector>
using namespace std;

class UnionFind{
private:
    vector<int> parent;
    vector<int> height;
public:
    explicit UnionFind(int size) {
        parent.resize(size);
        height.resize(size, 0);
        for (int i = 1; i < size; i++)
            parent[i] = i;
    }


    int findParent(int x) {
        if (x != parent[x]) {
            parent[x] = findParent(parent[x]);
        }

        return parent[x];
    }

    bool isSame(int x, int y) {
        return findParent(x) == findParent(y);
    }


    void unite(int x,int y) {
        int rootX = findParent(x);
        int rootY = findParent(y);
        if (height[rootX] > height[rootY]) {
            parent[rootY] = rootX;
        }
        else {
            parent[rootX] = rootY;
            if (height[rootY] == height[rootX])
                height[rootY]++;
        }
    }
};

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    UnionFind unionFind = UnionFind(edges.size()+1);

    for (auto& edge: edges) {
        if (!unionFind.isSame(edge[0], edge[1]))
            unionFind.unite(edge[0], edge[1]);
        else
            return edge;
    }
}

int main() {
    vector<vector<int>> edges {{1,2}, {2,3}, {3,4}, {1,4},{1,5}};
    auto edge = findRedundantConnection(edges);
    std::cout << edge[0] << ' ' <<edge[1]<< std::endl;
    return 0;
}
