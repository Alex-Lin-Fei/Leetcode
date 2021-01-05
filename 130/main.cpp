#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
void bfs(vector<vector<char>>& board) {
    queue<pair<int, int>> q;

    for (int i = 0; i < board.size(); i++) {
        if (board[i][0] == 'O')
            q.push(make_pair(i, 0));
        if (board[i][board[0].size() - 1] == 'O')
            q.push(make_pair(i, board[0].size() - 1));
    }
    for (int i = 1; i < board[0].size() - 1; i++) {
        if (board[0][i] == 'O')
            q.push(make_pair(0, i));
        if (board[board.size() - 1][i] == 'O')
            q.push(make_pair(board.size() - 1, i));
    }

    while (!q.empty()) {
        pair<int, int>temp = q.front();
        q.pop();
        board[temp.first][temp.second] = 'A';


        for (auto&i : dir)
        {
            int a = i[0] + temp.first;
            int b = i[1] + temp.second;
            if (a >= 0 && a < board.size() && b >=0 &&
            b<board[0].size() && board[a][b] == 'O')
                q.push(make_pair(a,b));
        }
    }


}
void solve(vector<vector<char>>& board) {
    bfs(board);
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[0].size(); j++)
            board[i][j] = (board[i][j] == 'A') ? 'O' : 'X';
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
