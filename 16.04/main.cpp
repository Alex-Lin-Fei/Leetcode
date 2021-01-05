#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>
using namespace std;

string tictactoe(vector<string>& board) {
//    判断行
    bool isWin = true;
    ostringstream ss;
    char ch;
    for (auto &row: board) {
        ch = row[0];
        isWin = true;
        for (auto &c: row)
            if (c != ch) {
                isWin = false;
                break;
            }
        if (isWin && ch != ' ') {
            ss << ch;
            return ss.str();
        }
    }

    //    判断列
    isWin = true;
    for (int i = 0; i < board.size(); i++) {
        ch = board[0][i];
        isWin = true;
        for (int j = 1; j < board.size(); j++)
            if (board[j][i] != ch) {
                isWin = false;
                break;
            }
        if (isWin && ch != ' ') {
            ss << ch;
            return ss.str();
        }
    }

//    判断对角线
    ch = board[0][0];
    int i;
    for (i = 1; i < board.size(); i++) {
        if (board[i][i] != ch)
            break;
    }

    if (i == board.size() && ch != ' ') {
        ss << ch;
        return ss.str();
    }

    ch = board[0][board.size() - 1];
    for (i = 1; i < board.size(); i++) {
        if (board[i][board.size() - 1 - i] != ch)
            break;
    }
    if (i == board.size() && ch != ' ') {
        ss << ch;
        return ss.str();
    }

    int sum = 0;
    for (auto &s: board) {
        for (auto &c: s)
            if (c != ' ')
                sum++;
    }
    return (sum == pow(board.size(), 2)) ? "Draw" : "Pending";

}

int main() {
    vector<string>s;

    s.emplace_back("   X O  O ");
    s.emplace_back(" X X    O ");
    s.emplace_back("X  X    O ");
    s.emplace_back("X    OX O ");
    s.emplace_back("X   XO  O ");
    s.emplace_back("X  X O  O ");
    s.emplace_back("O  X O  O ");
    s.emplace_back("     O  OX");
    s.emplace_back("     O  O ");
    s.emplace_back("   X XXXO ");







    std::cout << tictactoe(s) << std::endl;
    return 0;
}
