#include <iostream>
#include <algorithm>
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
        for (int i = 0; i < size; i++)
            parent[i] = i;
    }

    int findFather(int x) {
        if (x != parent[x]) {
            parent[x] = findFather(parent[x]);
        }

        return parent[x];
    }

    void unite(int a, int b) {
        int rootA = findFather(a);
        int rootB = findFather(b);

        if (height[rootB] > height[rootA])
            parent[rootA] = rootB;
        else {
            parent[rootB] = rootA;
            if (height[rootA] == height[rootB])
                height[rootA]++;
        }
    }

    bool isSame(int a,int b) {
        return findFather(a) == findFather(b);
    }
};


int swimInWater(vector<vector<int>>& grid) {
    int N = grid.size();
    UnionFind unionFind = UnionFind(N * N);

    vector<pair<int, int>> platforms;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            platforms.emplace_back(grid[i][j], i*N+j);


    sort(platforms.begin(), platforms.end());
    for (auto & platform : platforms) {
        int a = platform.second / N;
        int b = platform.second % N;
        if (a != 0 && grid[a - 1][b] < grid[a][b])
            unionFind.unite(a * N + b, (a - 1) * N + b);
        if (a != N - 1 && grid[a + 1][b] < grid[a][b])
            unionFind.unite(a * N + b, (a + 1) * N + b);
        if (b != 0 && grid[a][b - 1] < grid[a][b])
            unionFind.unite(a * N + b, a * N + b - 1);
        if (b != N - 1 && grid[a][b + 1] < grid[a][b])
            unionFind.unite(a * N + b, a * N + b + 1);
        if (unionFind.isSame(0, N * N - 1))
            return platform.first;
    }
}

int main() {
    vector<vector<int>> platforms{{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    std::cout << swimInWater(platforms) << std::endl;

    return 0;
}
