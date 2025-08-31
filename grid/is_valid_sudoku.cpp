// grid
// traversal
// sudoku

#include <vector>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int row = 0; row < 9; row++)
        {
            vector<bool> rows(9, false);
            vector<bool> cols(9, false);
            vector<bool> grid(9, false);
            for (int j = 0; j < 9; j++)
            {
                if (board[row][j] != '.')
                {
                    if (rows[board[row][j]])
                        return false;
                    else
                        rows[board[row][j]] = true;
                }
                if (board[j][row] != '.')
                {
                    if (cols[board[j][row]])
                        return false;
                    cols[board[j][row]] = true;
                }
                int _i = (row / 3) * 3 + j / 3;
                int _j = (row % 3) * 3 + j % 3;
                if (board[_i][_j] != '.')
                {
                    if (grid[board[_i][_j]])
                        return false;
                    else
                        grid[board[_i][_j]] = true;
                }
            }
        }
        return true;
    }
};