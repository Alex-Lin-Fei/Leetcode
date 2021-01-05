#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> father, height;

void init(int n) {
    father.clear();
    height.clear();
    father.resize(n);
    height.resize(n, 0);

    for (int i = 0; i < n; i++)
        father[i] = i;
}

int findFather(int x) {
    if(x!=father[x]){
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

    if (height[a] < height[b]) {
        father[a] = b;
    } else {
        father[b] = a;
        if (height[a] == height[b])
            height[a]++;
    }
}


int makeConnected(int n, vector<vector<int>>& connections) {
//    初始化
    init(n);
    set<int> s;
    int sum = 0;
//    合并并查集
    for (auto &c: connections) {
        if (!isSame(c[0], c[1])) {
            cout<<c[0]<<" "<<c[1]<<endl;
            unite(c[0], c[1]);
            sum++;
        }
    }

//    计数联通变量个数
    for (int i = 0; i < n; i++) {
        s.insert(findFather(i));
        cout<<father[i]<<" ";
    }

    int cnt = connections.size() - sum;
    cout<<"cnt:" <<cnt<<endl;
    cout<<"sum: "<<sum<<endl;
    if (s.size() - 1 <= cnt)
        return s.size() - 1;
    return -1;
}

int main() {
    vector<vector<int>> c={{1,5},{1,7},{1,2},{1,4},{3,7},{4,7},{3,5},{0,6},{0,1},{0,4},{2,6},{0,3},{0,2}};
    cout  << makeConnected(12, c);

    return 0;
}
