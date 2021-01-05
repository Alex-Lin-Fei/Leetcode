#include <iostream>
#include <vector>
using namespace std;

vector<int> ranks;
vector<int> father;

void init() {
    ranks.clear();
    ranks.resize(26, 0);
    father.clear();
    father.resize(26);
    for (int i = 0; i < 26; i++)
        father[i] = i;
}

int findFather(int x) {
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

    if (ranks[a] < ranks[b])
        father[a] = b;
    else {
        father[b] = a;
        if (ranks[a] == ranks[b])
            ranks[a]++;
    }
}

bool equationsPossible(vector<string>& equations) {
    init();

    for (auto& e: equations) {
        if (e[1] == '=') {
            int a = e[0] - 'a';
            int b = e[3] - 'a';
            if (!isSame(a, b))
                unite(a, b);
        }
    }

    for (auto& e: equations) {
        if (e[1] == '!') {
            int a = e[0] - 'a';
            int b = e[3] - 'a';
            if (isSame(a, b))
                return false;
        }
    }
    return true;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
