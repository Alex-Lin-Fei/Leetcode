#include <iostream>
#include <vector>
#include <map>
#include <set>
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


vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    UnionFind unionFind = UnionFind(accounts.size());
    map<int, set<string>> hash;
    map<string, int> father;

//    加边
   for (int i = 0; i < accounts.size(); i++)
       for (int j = 1; j < accounts[i].size(); j++) {
           if (!father.count(accounts[i][j]))
               father[accounts[i][j]] = i;

           else
               unionFind.unite(i, father[accounts[i][j]]);

       }

    for (int i = 0; i < accounts.size(); i++) {
        for (int j = 1; j < accounts[i].size(); j++)
            hash[unionFind.findFather(i)].insert(accounts[i][j]);
    }

    vector<vector<string>> ans;
    for (auto &item: hash) {
        vector<string> account;
//        账户名字
        account.push_back(accounts[item.first][0]);
//        加入邮箱
        for (auto &email: item.second)
            account.push_back(email);
        ans.push_back(account);
    }

    return ans;
}

int main() {
    vector<vector<string>> accounts = {{"Alex","Alex5@m.co","Alex4@m.co","Alex0@m.co"},{"Ethan","Ethan3@m.co","Ethan3@m.co","Ethan0@m.co"},
                                       {"Kevin","Kevin4@m.co","Kevin2@m.co","Kevin2@m.co"},{"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe2@m.co"},
                                       {"Gabe","Gabe3@m.co","Gabe4@m.co","Gabe2@m.co"}};

accountsMerge(accounts);


    return 0;
}
