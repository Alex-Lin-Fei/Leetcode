#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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

string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    UnionFind unionFind = UnionFind(s.size());
    map<int,vector<char>> hash;

    for (auto& pair:pairs) {
        if (!unionFind.isSame(pair[0], pair[1]))
            unionFind.unite(pair[0], pair[1]);
    }
    for (int i = 0; i < s.size(); i++)
        hash[unionFind.findFather(i)].push_back(s[i]);
    for (auto & v: hash)
       sort(v.second.begin(), v.second.end(), [](char a,char b){return a > b;});

    for (int i = 0; i < s.size(); i++) {
        s[i] = hash[unionFind.findFather(i)].back();
        hash[unionFind.findFather(i)].pop_back();
    }
    return s;
}

int main() {

    vector<vector<int>> pairs{{0,3}, {1,2}};
    std::cout <<smallestStringWithSwaps("dcab", pairs) << std::endl;
    return 0;
}
