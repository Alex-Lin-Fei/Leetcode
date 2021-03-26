#include <iostream>
#include <vector>
using namespace std;

int transfer(int val) {
    switch (val) {
        case 2:
            val = 0;
            break;
        case -1:
            val = 1;
            break;
        default:
            break;
    }
    return val;
}

int getNear(vector<vector<int>>& board, int i, int j) {
    int sum = 0;

    sum += (i == 0 ? 0 : transfer(board[i - 1][j]));
    sum += (i == board.size() - 1 ? 0 : transfer(board[i + 1][j]));
    sum += (j == 0 ? 0 : transfer(board[i][j - 1]));
    sum += (j == board[0].size() - 1 ? 0 : transfer(board[i][j + 1]));
    sum += (i != 0 && j != 0 ? transfer(board[i - 1][j - 1]): 0);
    sum += (i != 0 && j != board[0].size() - 1 ? transfer(board[i - 1][j + 1]): 0);
    sum += (i != board.size() - 1 && j != 0 ? transfer(board[i + 1][j - 1]): 0);
    sum += (i != board.size() - 1 && j != board[0].size() - 1 ? transfer(board[i + 1][j + 1]): 0);

    return sum;
}

void gameOfLife(vector<vector<int>>& board) {
//    死细胞复活设置为2 活细胞死去设置为-1
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            int sum = getNear(board, i, j);
            if (board[i][j]) {
                if (sum != 2 && sum != 3)
                    board[i][j] = -1;
            } else {
                if (sum == 3)
                    board[i][j] = 2;
            }
        }
    }

    for (auto &row: board) {
        for (auto &i: row) {
            if (i == 2)
                i = 1;
            else if (i == -1)
                i = 0;
            cout << i << ' ';
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> board{{1,1}, {1, 0}};
    gameOfLife(board);

    return 0;
}
