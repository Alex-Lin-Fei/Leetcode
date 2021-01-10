#include <iostream>
#include <vector>
using namespace std;

vector<int> father;
vector<int> height;

void init() {
    father.resize(26);
    height.resize(26, 0);
    for (int i = 0; i < father.size(); i++)
        father[i] = i;
}

int findFather(int a) {
    while (a != father[a]) {
        a = father[a];
    }
    return a;
}

void unite(int a, int b) {
    a = findFather(a);
    b = findFather(b);

    if (height[a] < height[b])
        father[a] = b;

    else {
        father[b] = a;
        if (height[b] == height[a])
            height[a]++;
    }
}

bool isSame(int a, int b) {
    return findFather(a) == findFather(b);
}

bool equationsPossible(vector<string>& equations) {
    init();


    for (auto &equation: equations)
        if (equation[1] == '=') {
            int a = equation[0] - 'a';
            int b = equation[3] - 'a';
            if (!isSame(a, b))
                unite(a, b);
        }

    for (auto &equation: equations)
        if (equation[1] == '!') {
            int a = equation[0] - 'a';
            int b = equation[3] - 'a';
            if (isSame(a, b))
                return false;
        }
    return true;
}

int main() {
    vector<string> equations{"c==c","b==d","x!=z"};
    cout <<equationsPossible(equations)<<endl;

    return 0;
}