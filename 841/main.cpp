#include <iostream>
#include <vector>
using namespace std;

vector<bool>visited;

void dfs(vector<vector<int>>& rooms, int idx) {
    visited[idx] = true;

    for (auto& i: rooms[idx]) {
        if (!visited[i])
            dfs(rooms, i);
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    visited.resize(rooms.size());
    dfs(rooms, 0);
    for (auto && i : visited)
        if (!i)
            return false;
    return true;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
