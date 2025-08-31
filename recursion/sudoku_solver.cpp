// grid
// sudoku
// recursion

#include <vector>

using namespace std;

class Solution
{
public:
    bool row_dp[9][9] = {false};
    bool col_dp[9][9] = {false};
    bool box_dp[9][9] = {false};

    bool isValid(vector<vector<char>> &board, int row, int col, int num)
    {
        if (row_dp[row][num])
            return false;
        if (col_dp[col][num])
            return false;
        int box_num = (row / 3) * 3 + col / 3;
        if (box_dp[box_num][num])
            return false;
        return true;
    }

    bool solve(vector<vector<char>> &board, int row, int col)
    {
        for (int i = row; i < 9; i++)
        {
            int j = i == row ? col : 0;
            for (; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    int solvable = false;
                    for (int num = 0; num < 9; num++)
                    {
                        if (isValid(board, i, j, num))
                        {
                            board[i][j] = '1' + num;
                            row_dp[i][board[i][j] - '1'] = true;
                            col_dp[j][board[i][j] - '1'] = true;
                            int box_num = (i / 3) * 3 + j / 3;
                            box_dp[box_num][board[i][j] - '1'] = true;
                            solvable = solve(board, i, j);
                            if (solvable)
                            {
                                break;
                            }
                            else
                            {
                                row_dp[i][board[i][j] - '1'] = false;
                                col_dp[j][board[i][j] - '1'] = false;
                                int box_num = (i / 3) * 3 + j / 3;
                                box_dp[box_num][board[i][j] - '1'] = false;
                                board[i][j] = '.';
                            }
                        }
                    }
                    if (!solvable)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    void preProcess(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    row_dp[i][board[i][j] - '1'] = true;
                    col_dp[j][board[i][j] - '1'] = true;
                    int box_num = (i / 3) * 3 + j / 3;
                    box_dp[box_num][board[i][j] - '1'] = true;
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        preProcess(board);
        solve(board, 0, 0);
    }
};