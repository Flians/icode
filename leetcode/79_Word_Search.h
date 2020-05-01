#include "../base/icode.h"

class L79 : public icode
{
public:
    bool word_search(int row, int col, int index, vector<vector<char>> &board, string word)
    {
        if (index >= (int)word.length())
            return true;
        if (row >= (int)board.size() || col >= (int)board[0].size() || row < 0 || col < 0 || board[row][col] != word[index])
            return false;
        int cur = board[row][col];
        board[row][col] = 0;
        bool res = word_search(row + 1, col, index + 1, board, word) || word_search(row - 1, col, index + 1, board, word) || word_search(row, col + 1, index + 1, board, word) || word_search(row, col - 1, index + 1, board, word);
        board[row][col] = cur;
        return res;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        if (word.empty())
            return true;
        int i = 0, j = 0;
        for (; i < (int)board.size(); ++i)
        {
            for (j = 0; j < (int)board[0].size(); ++j)
            {
                if (board[i][j] == word[0] && word_search(i, j, 0, board, word))
                    return true;
            }
        }
        return false;
    }

    void run()
    {
        vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
        cout << exist(board, "ABCB") << endl;
    }
};