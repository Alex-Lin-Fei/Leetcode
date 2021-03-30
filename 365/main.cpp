#include <iostream>
#include <stack>
#include <set>
using namespace std;

bool dfs(int & jug1Capacity, int & jug2Capacity, int x, int y, int & targetCapacity, set<pair<int, int>> & visited) {


    return false;
}

//dfs超时
/*
bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
    set<pair<int, int>> visited;
    stack<pair<int, int>> stk;

    stk.push({0, 0});

    while (!stk.empty()) {
        auto now = stk.top();
        stk.pop();

        int x = now.first, y = now.second;

        if (visited.count({x, y}))
            continue;

        if (x == targetCapacity || y == targetCapacity || x + y == targetCapacity)
            return true;
        visited.insert({x, y});

//        装满x
        stk.push({jug1Capacity, y});

//       装满y
        stk.push({x, jug2Capacity});

//        清空x
        stk.push({0, y});
//        清空y

        stk.push({x, 0});

//       x倒入y

        stk.push({max(0, x - (jug2Capacity - y)), min(x + y, jug2Capacity)});

//       y倒入x

        stk.push({min(x + y, jug1Capacity), max(0, y - (jug1Capacity - x))});
    }


    return false;
}
*/

//贝祖定理

//默认b大于a
int gcd(int a, int b) {
    if (b % a == 0)
        return a;
    else {
        return gcd(b % a, a);
    }
}

bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
    if (jug1Capacity + jug2Capacity < targetCapacity)
        return false;
    return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
}


int main() {
    std::cout << canMeasureWater(104579,
    104593,
    12444) << std::endl;
    return 0;
}
