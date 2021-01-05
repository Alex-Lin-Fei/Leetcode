#include <iostream>
#include <vector>
using namespace std;

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool dfs(vector<vector<char>>& board, string word, int cur, int now) {
    int x = now / board[0].size();
    int y = now % board[0].size();
    if (board[x][y] != word[cur])
        return false;
    else if (cur == word.size() - 1)
        return true;
    else {
        char temp = board[x][y];
        board[x][y] = '.';
        for (auto &d: dir) {
            int a = x + d[0];
            int b = y + d[1];
            if (a < 0 || a >= board.size() || b < 0 || b >= board[0].size())
                continue;

            if (dfs(board, word, cur + 1, a * board[0].size() + b))
                return true;
        }
        board[x][y] = temp;
    }

    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[0].size(); j++)
            if (dfs(board, word, 0, i * board[0].size() + j))
                return true;
    return false;
}

int main() {
    vector<vector<char>> board =
            {{'a'}};
    string word = "a";
    cout << exist(board, word);
    return 0;
}
