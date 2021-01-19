#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
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

    int findFather(int x) {
        cout << x <<' ' <<father[x] <<endl;
        if (x != father[x]) {
            father[x] = findFather(father[x]);
        }
        return father[x];
    }

    bool isSame(int a, int b) {
        return findFather(a) == findFather(b);
    }


    void unite(int a, int b) {
        a = findFather(a);
        b = findFather(b);

        father[b] = a;
    }
};

int minCostConnectPoints(vector<vector<int>>& points) {
//    构边  tuple of u,v,w
    UnionFind unionFind = UnionFind(points.size());
    int ans = 0;
    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            edges.emplace_back(i, j, w);
        }
    }

    sort(edges.begin(), edges.end(), [](tuple<int, int, int> a, tuple<int, int, int> b) {
        return get<2>(a) < get<2>(b);
    });

    for (auto &edge: edges) {
//        cout <<get<0>(edge)<< get<1>(edge);
        if (!unionFind.isSame(get<0>(edge), get<1>(edge))) {
            unionFind.unite(get<0>(edge), get<1>(edge));
            ans += get<2>(edge);
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> points{{-1000000,-1000000}};

    std::cout << minCostConnectPoints(points) << std::endl;
    return 0;
}
