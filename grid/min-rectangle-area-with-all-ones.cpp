// grid

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minimumArea(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        int min_col = cols - 1;
        int max_col = 0;
        int min_row = rows - 1;
        int max_row = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
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

        int length = max_row - min_row + 1;
        int height = max_col - min_col + 1;
        return length * height;
    }
};