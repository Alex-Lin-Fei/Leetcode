#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dir{0,1,0,-1,0};

class UnionFind {
private:
    vector<int> father;
    vector<int> number;

public:
    explicit UnionFind(int size) {
        father.resize(size);
        number.resize(size, 1);

        for (int i = 0; i < size; i++)
            father[i] = i;
    }

    bool isSame(int a,int b) {
        return findFather(a) == findFather(b);
    }

    int findFather(int x) {
        if (x != father[x])
            father[x] = findFather(father[x]);
        return father[x];
    }

    void unite(int a, int b) {
        a = findFather(a);
        b = findFather(b);

        father[b] = a;
        number[a] += number[b];
    }

    int getNumber(int x) {
        x = findFather(x);
        return number[x];
    }
};

vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
    auto copy = grid;
    for (auto &hit: hits)
        grid[hit[0]][hit[1]] = 0;

    vector<int> ans;

    int m = grid.size();
    int n = grid[0].size();

    UnionFind unionFind = UnionFind(m * n + 1);

//    连接屋顶
    for (int j = 0; j < n; j++)
        if (grid[0][j])
            unionFind.unite(m * n, 0 * n + j);

//    内部连接
    for (int i = 1; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j]) {
                if (grid[i - 1][j])
                    unionFind.unite((i - 1) * n + j, i * n + j);
                if (j > 0 && grid[i][j - 1])
                    unionFind.unite(i * n + j - 1, i * n + j);
            }

//    加砖头
    for (int j = hits.size()-1; j >= 0; j--) {
        auto hit = hits[j];
        if (copy[hit[0]][hit[1]]) {
            int origin = unionFind.getNumber(m * n);

            if (hit[0] == 0)
                unionFind.unite(m*n, hit[0] * n + hit[1]);

//            四个方向

            for (int i = 0; i < 4; i++) {
                int x = hit[0] + dir[i];
                int y = hit[1] + dir[i + 1];


                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y]) {
                    if (!unionFind.isSame(x * n + y, hit[0] * n + hit[1]))
                        unionFind.unite(x * n + y, hit[0] * n + hit[1]);
                }
            }

            int current = unionFind.getNumber(m * n);
            ans.push_back(max(0, current - origin - 1));
            //            补回
            grid[hit[0]][hit[1]] = 1;

        }
        else
            ans.push_back(0);
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    vector<vector<int>> grid{{1,0,1},{0,0,1}};
    vector<vector<int>> hits{{1,0},{0,0}};
    auto ans = hitBricks(grid,hits);
    for (int i: ans)
        cout << i <<' ';

    return 0;
}
