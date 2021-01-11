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


int removeStones(vector<vector<int>>& stones) {
    UnionFind unionFind = UnionFind(stones.size());

    for (int i = 0; i < stones.size(); i++)
        for (int j = i + 1; j < stones.size(); j++) {
//            同行或同列
            if (stones[i][0] == stones[j][0] ||
                stones[i][1] == stones[j][1]) {
                unionFind.unite(i, j);
            }
        }
    int ans = 0;
    for (int i = 0; i < stones.size(); i++)
        if (i == unionFind.findFather(i))
            ans++;
    return stones.size() - ans;
}

int main() {
    vector<vector<int>> stones {{0,0},{0,2},{1,1},{2,0},{2,2}};
    std::cout << removeStones(stones) << std::endl;
    return 0;
}
