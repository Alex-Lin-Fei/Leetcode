#include <iostream>
#include <tuple>
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

int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    int size = m * n;
    UnionFind unionFind = UnionFind(size);

//    为边排序  每个位置的边为右方向和下方的点以及绝对值组成
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
//            往下的边
            if (i != m - 1)
                edges.emplace_back(i * n + j, i * n + j + n, abs(heights[i][j] - heights[i + 1][j]));
//            往右的边
            if (j != n - 1)
                edges.emplace_back(i * n + j, i * n + j + 1, abs(heights[i][j] - heights[i][j + 1]));
        }
    sort(edges.begin(), edges.end(), [](tuple<int, int, int> a, tuple<int, int, int> b) {
        return get<2>(a) < get<2>(b);
    });

//        加边
    for (auto &edge: edges) {
        if (!unionFind.isSame(get<0>(edge), get<1>(edge)))
            unionFind.unite(get<0>(edge), get<1>(edge));
        if (unionFind.isSame(0, m * n - 1))
            return get<2>(edge);
    }

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
