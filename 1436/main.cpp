#include <iostream>
#include <vector>
#include <map>
using namespace std;

string destCity(vector<vector<string>>& paths) {
    map<string, bool> visited;

    for (auto &path: paths) {
        if (!visited.count(path[1]))
            visited[path[1]] = true;
        visited[path[0]] = false;
    }

    for (auto &item: visited)
        if (item.second)
            return item.first;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
