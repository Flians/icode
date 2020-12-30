#include "../base/icode.hpp"
class L289 : public icode
{
public:
	void run() {
        vector<vector<int>> nums = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
        gameOfLife(nums);
        print_res(move(nums));
    }

    void gameOfLife(vector<vector<int>>& board) {
        int nbr[] = {0, 1, -1};
        for (int i = 0, n = board.size(); i < n; ++i) {
            for (int j = 0, m = board[i].size(); j < m; ++j) {
                int live = 0;
                for (int x = 0; x < 3; ++x) {
                    for (int y = 0; y < 3; ++y) {
                        if (nbr[x] != 0 || nbr[y] != 0) {
                            int c = nbr[x] + j, r = nbr[y] + i;
                            if (c >= 0 && c < m && r >= 0 && r < n && board[r][c] > 0) ++live;
                        }
                    }
                }
                if (board[i][j] && (live < 2 || live > 3)) {
                    board[i][j] = 2;
                } else if (!board[i][j] && live == 3){
                    board[i][j] = -1;
                }
            }
        }
        for (int i = 0, n = board.size(); i < n; ++i) {
            for (int j = 0, m = board[i].size(); j < m; ++j) {
                if (board[i][j]*board[i][j] == 1) {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }
};