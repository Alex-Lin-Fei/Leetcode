#include <iostream>
#include <queue>
#include <set>
using namespace std;

int getKthMagicNumber(int k) {
    priority_queue<long long, vector<long long>, greater<long long>> que;
    set<long long> visited;
    long long tmp;

    que.push(1);
    visited.insert(1);

    while (!que.empty()) {
        tmp = que.top();
        que.pop();
        visited.erase(tmp);

        if (--k == 0)break;


        if (!visited.count(tmp * 3)) {
            visited.insert(tmp * 3);
            que.push(tmp * 3);
        }

        if (!visited.count(tmp * 5)) {
            visited.insert(tmp * 5);
            que.push(tmp * 5);
        }

        if (!visited.count(tmp * 7)) {
            visited.insert(tmp * 7);
            que.push(tmp * 7);
        }
    }

    return tmp;
}

int main() {
    cout << getKthMagicNumber(643);
    return 0;
}
