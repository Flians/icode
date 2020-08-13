#include "../base/icode.hpp"
class L130 : public icode
{
public:
	void run() {
        vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
        solve(board);
        print_res(board);
    }

    void dfs(int x, int y, vector<vector<char>>& board) {
        if (x < 0 || x >= (int)board.size() || y < 0 || y >= (int)board[0].size() || board[x][y] != 'O')
            return;
        board[x][y] = 'A';
        dfs(x - 1, y, board);
        dfs(x + 1, y, board);
        dfs(x, y - 1, board);
        dfs(x, y + 1, board);

    }
    
    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;
        for (size_t i = 0; i < board.size(); ++i) {
            dfs(i, 0, board);
            dfs(i, board[0].size()-1, board);
        }
        for (size_t i = 0; i < board[0].size(); ++i) {
            dfs(0, i, board);
            dfs(board.size()-1, i, board);
        }
        for (size_t i = 0; i < board.size(); ++i) {
            for (size_t j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};