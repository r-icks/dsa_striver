// grid
// dp

#include <vector>
#include <cstring>
#include <climits>

using namespace std;

class Solution
{
public:
    int dp[30][30][30][30];

    int minimumSum(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        memset(dp, -1, sizeof(dp));

        int mini = INT_MAX;
        for (int i = 1; i < rows - 1; i++)
        {
            for (int j = i + 1; j < rows; j++)
            {
                mini = min(
                    (minimumArea(grid, 0, i - 1, 0, cols - 1) + minimumArea(grid, i, j - 1, 0, cols - 1) + minimumArea(grid, j, rows - 1, 0, cols - 1)), mini);
            }
        }
        for (int i = 1; i < cols - 1; i++)
        {
            for (int j = i + 1; j < cols; j++)
            {
                mini = min(
                    (minimumArea(grid, 0, rows - 1, 0, i - 1) + minimumArea(grid, 0, rows - 1, i, j - 1) + minimumArea(grid, 0, rows - 1, j, cols - 1)), mini);
            }
        }
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                mini = min(
                    (minimumArea(grid, 0, rows - 1, 0, j - 1) + minimumArea(grid, 0, i - 1, j, cols - 1) + minimumArea(grid, i, rows - 1, j, cols - 1)), mini);
                mini = min(
                    (minimumArea(grid, 0, i - 1, 0, j - 1) + minimumArea(grid, i, rows - 1, 0, j - 1) + minimumArea(grid, 0, rows - 1, j, cols - 1)), mini);
                mini = min(
                    (minimumArea(grid, 0, i - 1, 0, cols - 1) + minimumArea(grid, i, rows - 1, 0, j - 1) + minimumArea(grid, i, rows - 1, j, cols - 1)), mini);
                mini = min(
                    (minimumArea(grid, 0, i - 1, 0, j - 1) + minimumArea(grid, 0, i - 1, j, cols - 1) + minimumArea(grid, i, rows - 1, 0, cols - 1)), mini);
            }
        }
        return mini;
    }

    int minimumArea(vector<vector<int>> &grid, int rowStart, int rowEnd, int colStart, int colEnd)
    {
        int &res = dp[rowStart][rowEnd][colStart][colEnd];
        if (res != -1)
            return res;

        int min_row = rowEnd;
        int max_row = rowStart;
        int min_col = colEnd;
        int max_col = colStart;

        for (int i = rowStart; i <= rowEnd; i++)
        {
            for (int j = colStart; j <= colEnd; j++)
            {
                if (grid[i][j] == 1)
                {
                    min_row = min(min_row, i);
                    max_row = max(max_row, i);
                    min_col = min(min_col, j);
                    max_col = max(max_col, j);
                }
            }
        }

        if (min_row > max_row || min_col > max_col)
        {
            return res = 1;
        }

        int length = max_row - min_row + 1;
        int width = max_col - min_col + 1;

        return res = (length * width);
    }
};