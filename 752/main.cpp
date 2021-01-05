#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;


int openLock(vector<string>& deadends, string target) {
    set<string> dead;
    set<string> visited;
    for (auto &d: deadends)
        dead.insert(d);

    queue<string> q;
    if (dead.count("0000"))
        return -1;
    q.push("0000");
    visited.insert("0000");

    int step = 0;
    while (!q.empty()) {
        int sz = q.size();

        while (sz--) {
            string temp = q.front();
            q.pop();

            if (temp == target)
                return step;

            for (int i = 0; i < 4; i++) {
//                正向
                int num = temp[i] - '0';
                temp[i] = (num + 1) % 10 + '0';
                if (!dead.count(temp) && !visited.count(temp)) {
                    q.push(temp);
                    visited.insert(temp);
                }
//                反向
                temp[i] = (num - 1 + 10) % 10 + '0';
                if (!dead.count(temp) && !visited.count(temp)) {
                    q.push(temp);
                    visited.insert(temp);
                }

//                恢复
                temp[i] = num + '0';
            }
        }
        step++;
    }
    return -1;
}

int main() {
    vector<string>v;
    v.push_back("0201");
    v.push_back("0101");
    v.push_back("0102");
    v.push_back("1212");
    v.push_back("2002");
string target = "0202";
cout<< openLock(v, target);

    return 0;
}
