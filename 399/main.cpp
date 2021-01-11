#include <iostream>
#include <vector>
#include <map>
using namespace std;

class UnionFind{
private:
    vector<int> parent;
    vector<double> weight;
public:
    explicit UnionFind(int size) {
        parent.resize(size);
        weight.resize(size, 1.0);
        for (int i = 0; i < size; i++)
            parent[i] = i;
    }

    int findParent(int x) {
        if (x!=parent[x]) {
            int p = parent[x];
            parent[x] = findParent(parent[x]);
            weight[x] *= weight[p];
        }

        return parent[x];
    }

    void unite(int a, int b, double value) {
        int rootA = findParent(a);
        int rootB = findParent(b);
        parent[rootA] = rootB;
        weight[rootA] = weight[b] * value / weight[a];
    }

    double isConnected(int a, int b) {
        if (findParent(a) != findParent(b))
            return -1.0;
        else
            return weight[a] / weight[b];
    }

};

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//    初始化
    int size = equations.size();
    UnionFind unionFind = UnionFind(2 * size);
    map<string, int> hash;
    int id = 0;

//    合边
    for (int i = 0; i < size; i++) {
        string var1 = equations[i][0];
        string var2 = equations[i][1];
        if (!hash.count(var1))
            hash[var1] = id++;
        if (!hash.count(var2))
            hash[var2] = id++;
        unionFind.unite(hash[var1], hash[var2], values[i]);
    }

//    查询
    vector<double> res;
    for (auto &query: queries) {
        string var1 = query[0];
        string var2 = query[1];
        if (!hash.count(var1) || !hash.count(var2))
            res.push_back(-1);
        else {
            int id1 = hash[var1];
            int id2 = hash[var2];
            res.push_back(unionFind.isConnected(id1, id2));
        }
    }

    return res;
}

int main() {
    vector<vector<string>> equations = {{"a","b"}};
    vector<double> values={0.5};
    vector<vector<string>> queries= {{"a","b"},{"b","a"},{"a","c"},{"x","y"}};
    auto res = calcEquation(equations,values,queries);
    for (auto& item: res)
        cout << item<<' ';

    return 0;
}
