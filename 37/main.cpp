#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

struct Node {
    pair<int, int> p;
    vector<int> possible;
    Node (int x, int y) {
        p.first = x;
        p.second = y;
    }

    bool operator<(const Node & node) const {
        return possible.size() < node.possible.size();
    }
};

vector<bool> vals(9, true);
//priority_queue<Node> que;
vector<Node> nodes;
bool hasFind=false;

void initPossible(Node& node, vector<vector<char>>& board) {
//    行
    int x = node.p.first;
    int y = node.p.second;
    for (auto &c: board[x])
        if (isdigit(c)) {
            vals[c - '0' - 1] = false;
        }
//    列
    for (auto &c: board)
        if (isdigit(c[y])) {
            vals[c[y] - '0' - 1] = false;
        }
//    格子
    int r = x / 3, c = y / 3;
    for (int i = r * 3; i < r * 3 + 3; i++)
        for (int j = c * 3; j < c * 3 + 3; j++)
            if (isdigit(board[i][j]))
                vals[board[i][j] - '0' - 1] = false;
    for (int i = 0; i < 9; i++)
        if (vals[i])
            node.possible.push_back(i + 1);
    vals.assign(vals.size(), true);
}

void delPossible(int x, int y, vector<vector<char>>& board, int idx) {
    int val = board[x][y] - '0';
//    行
    for (int i = 0; i < board[x].size(); i++)
        if (board[x][i] == '.') {
//            查找对应节点
            for (auto &node: nodes) {
                if (node.p == pair<int, int>(x, i)) {
                    for (auto it = node.possible.begin(); it != node.possible.end(); it++) {
                        if (*it == val) {
                            node.possible.erase(it);
                            break;
                        }
                    }
                    break;
                }
            }
        }

//    列
    for (int i = 0; i < board.size(); i++) {
        if (board[i][y] == '.') {
            for (auto &node: nodes) {
                if (node.p == pair<int, int>(i, y)) {
                    for (auto it = node.possible.begin(); it != node.possible.end(); it++) {
                        if (*it == val) {
                            node.possible.erase(it);
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
//    格子
    int r = x / 3, c = y / 3;
    for (int i = r * 3; i < r * 3 + 3; i++)
        for (int j = c * 3; j < c * 3 + 3; j++)
            if (board[i][j] == '.') {
                for (auto &node: nodes) {
                    if (node.p == pair<int, int>(i, j)) {
                        for (auto it = node.possible.begin(); it != node.possible.end(); it++) {
                            if (*it == val) {
                                node.possible.erase(it);
                                break;
                            }
                        }
                        break;
                    }
                }
            }
}

void solve(vector<vector<char>>& board, int idx) {
    if (idx == nodes.size()) {
//        找全了
        hasFind = true;
////        exit(0);
        return;
    } else {
        sort(nodes.begin()+idx+1, nodes.end());
        int x = nodes[idx].p.first;
        int y = nodes[idx].p.second;
        for (auto &v: nodes[idx].possible) {
            if (!hasFind) {
                board[x][y] = (char) (v + '0');
                delPossible(x, y, board, idx);
//                更改其他空格权限
                solve(board, idx + 1);
//            改回
                if (!hasFind) {
                    board[x][y] = '.';
                    for (int i = idx + 1; i < nodes.size(); i++) {
                        nodes[i].possible.clear();
                        initPossible(nodes[i], board);
                    }
                }
            }
        }
    }
}

void solveSudoku(vector<vector<char>>& board) {
//    可能的值
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == '.') {
                Node node(i, j);
                initPossible(node, board);
                nodes.push_back(node);
            }
        }
    }
    sort(nodes.begin(), nodes.end());

//    try
    solve(board, 0);
}

vector<pair<int, int>> spaces;
bool rows[9][9], col[9][9], block[3][3][9];
bool valid = false;
void dfs(vector<vector<char>>& board, int pos) {
    if (pos == spaces.size()) {
        valid = true;
        return;
    }
    else {
        int x = spaces[pos].first;
        int y = spaces[pos].second;

        for (int idx = 0; idx < 9 && !valid; idx++) {
            if (!rows[x][idx] && !col[y][idx] && !block[x/3][y/3][idx]) {
                rows[x][idx] = col[y][idx] = block[x/3][y/3][idx] = true;
                board[x][y] = '0'+idx + 1;
                dfs(board, pos+1);
                rows[x][idx] = col[y][idx] = block[x/3][y/3][idx] = false;
            }
        }
    }
}

void solveII(vector<vector<char>> & board) {
    memset(rows, false, sizeof(rows));
    memset(col, false, sizeof(col));
    memset(block, false, sizeof(block));
    valid = false;

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
                spaces.emplace_back(i,j);
            else
            {
                int digit = board[i][j] - '0' - 1;
                rows[i][digit] = col[j][digit] = block[i/3][j/3][digit] = false;
            }
        }
    dfs(board,0);
}

int main() {
    vector<vector<char>> board = {{'.', '.', '9', '7', '4', '8', '.', '.', '.'},
                                  {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
                                  {'.', '2', '.', '1', '.', '9', '.', '.', '.'},
                                  {'.', '.', '7', '.', '.', '.', '2', '4', '.'},
                                  {'.', '6', '4', '.', '1', '.', '5', '9', '.'},
                                  {'.', '9', '8', '.', '.', '.', '3', '.', '.'},
                                  {'.', '.', '.', '8', '.', '3', '.', '2', '.'},
                                  {'.', '.', '.', '.', '.', '.', '.', '.', '6'},
                                  {'.', '.', '.', '2', '7', '5', '9', '.', '.'}};
    solveSudoku(board);
//solveII(board);
//    vector<int>v(9);
//    for (int i = 0; i < 9; i++)
//        v[i] = i;
//    for (auto it = v.begin(); it != v.end(); it++)
//        if (*it == 3) {
//            v.erase(it);
//            break;
//        }
//    for (auto& i: v)
//        cout <<i <<' ';
//    cout << v.size();

    for (auto &row: board) {
        for (auto &c: row)
            cout << c << ' ';
        cout << endl;
    }
    return 0;
}
