#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

class UnionFind {
private:
    vector<int> father;

public:
    explicit UnionFind(int size) {
        father.resize(size);

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
    }
};


vector<int> dir{1,0,-1,0,1};
//广度优先搜索
bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
//    UnionFind unionFind = UnionFind()
    int n = 1000000;
    queue<vector<int>> que;
    set<vector<int>> visited;
    set<vector<int>> blocks;

//    将blocked中的Vector加入set中便于访问
    for (auto &block: blocked)
        blocks.insert(block);

//将紧贴左壁和下壁的封锁加入queue
    for (auto &block: blocks)
        if (block[1] == 0 || block[0] == n - 1) {
            que.push(block);
            visited.insert(block);
        }

    while (!que.empty()) {
        int x = que.front()[0];
        int y = que.front()[1];
        que.pop();

//        判断是否到达上壁和右壁
        if (x == 0 || y == n - 1)
            return false;

//        上下左右
        for (int i = 0; i < 4; i++) {
            int a = x + dir[i];
            int b = y + dir[i + 1];

            if (a >= 0 && a < n && b >= 0 && b < n &&
                blocks.count({a, b}) && !visited.count({a, b})) {
                que.push({a, b});
                visited.insert({a, b});
            }
        }

    }


    return true;
}

int main() {
    vector<vector<int>> blocked{{0,1},{1,0}};
    vector<int> source{0,0};
    vector<int> target{999999,999999};
    std::cout << isEscapePossible(blocked, source, target) << std::endl;
    return 0;
}
