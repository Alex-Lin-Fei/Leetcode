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


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
