#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for (int y = 0; y < board[0].size(); y++) {
            if (board[0][y] == 'O') {
                dfs(board, 0, y);
            }
            if (board[board.size() - 1][y] == 'O') {
                dfs(board, board.size() - 1, y);
            }
        }
        for (int x = 0; x < board.size(); x++) {
            if (board[x][0] == 'O') {
                dfs(board, x, 0);
            }
            if (board[x][board[x].size() - 1] == 'O') {
                dfs(board, x, board[x].size() - 1);
            }
        }

        for (int x = 0; x < board.size(); x++) {
            for (int y = 0; y < board[x].size(); y++) {
                if (board[x][y] == 'O') {
                    board[x][y] = 'X';
                }
            }
        }

        for (int x = 0; x < board.size(); x++) {
            for (int y = 0; y < board[x].size(); y++) {
                if (board[x][y] == 'A') {
                    board[x][y] = 'O';
                }
            }
        }
    }


    void dfs(vector<vector<char>>& board, int x, int y) {
        if (outBoundary(x, y, board.size() - 1, board[0].size() - 1) || board[x][y] == 'X' || board[x][y] == 'A') {
            return;
        }

        board[x][y] = 'A';

        dfs(board, x - 1, y);
        dfs(board, x + 1, y);
        dfs(board, x, y - 1);
        dfs(board, x, y + 1);
    }


    bool outBoundary(int x, int y, int _x, int _y) {
        if (x < 0 || x > _x || y < 0 || y > _y) {
            return true;
        }

        return false;
    }
};


int main() {
    vector<vector<char>> board = {{'O', 'O'}, {'O', 'O'}};

    Solution solution;

    solution.solve(board);

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j];
        }
    }
}