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

int regionsBySlashes(vector<string>& grid) {
    int ans = 1;
    int N = grid.size() + 1;
    UnionFind unionFind = UnionFind(N*N);

//    初始化 将边界的点连接起来
    for (int i = 0; i < N - 1; i++) {
        unionFind.unite(i, i + 1);
        unionFind.unite((N-1) * N + i, (N-1) * N + i + 1);
    }

    for (int j = 0; j < N - 1; j++) {
        unionFind.unite(j*N, (j+1)*N);
        unionFind.unite(j * N + N-1, (j + 1) * N + N-1);
    }


//   不断加入边 若出现连接同一集合中的点 则增加划分区域
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            char ch = grid[i][j];
            if (ch != ' ') {
                if (ch == '/') {
                    int a = i * N + j + 1;
                    int b = (i + 1) * N + j;
                    if (unionFind.isSame(a, b))
                        ans++;
                    unionFind.unite(a, b);
                } else if (ch == '\\') {
                    int a = i * N + j;
                    int b = (i + 1) * N + j + 1;
                    if (unionFind.isSame(a, b))
                        ans++;
                    unionFind.unite(a, b);
                }
            }
        }
    }

    return ans;
}

int main() {
    vector<string> grid{"\\/", "/\\"};
    cout << regionsBySlashes(grid);
    return 0;
}
