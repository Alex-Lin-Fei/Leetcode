#include <iostream>
#include <vector>
using namespace std;


vector<bool> visited;
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

bool dfs(int start, vector<vector<char>>& board, string word, int nex) {
    if (nex == word.size())
        return true;
    int x = start / board[0].size();
    int y = start % board[0].size();

    for (auto &d: dir) {
        int a = d[0] + x;
        int b = d[1] + y;
        if (a >= 0 && a < board.size() && b >= 0 && b < board[0].size() &&
        board[a][b] == word[nex] && !visited[a * board[0].size() + b]) {
            visited[a * board[0].size() + b]=true;
            if(dfs(a * board[0].size() + b, board, word, nex + 1))
                return true;
            visited[a * board[0].size() + b]=false;
        }
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    visited.clear();
    visited.resize(board.size()*board[0].size());
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[0].size(); j++)
            if (board[i][j] == word[0]) {
                visited.assign(visited.size(), false);
                visited[i*board[0].size()+j]=true;
                if (dfs(i * board[0].size() + j, board, word, 1))
                    return true;
            }
    return false;
}

int main() {
    vector<vector<char>> v={{'a', 'a'}};
    std::cout << exist(v, "aaa") << std::endl;
    return 0;
}
