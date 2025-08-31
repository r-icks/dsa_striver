// recursion
// grid

#include <iostream>

using namespace std;

class Solution
{
public:
    int traverse(vector<vector<int>> &grid, int row, int col, int count, int walkable)
    {
        if (row == grid.size() || col == grid[0].size() || row < 0 || col < 0 || grid[row][col] == -1)
            return 0;
        count++;
        if (grid[row][col] == 2)
        {
            return count == walkable;
        }
        int ans = 0;
        grid[row][col] = -1;
        ans += traverse(grid, row + 1, col, count, walkable);
        ans += traverse(grid, row - 1, col, count, walkable);
        ans += traverse(grid, row, col + 1, count, walkable);
        ans += traverse(grid, row, col - 1, count, walkable);
        grid[row][col] = 0;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int startI = 0;
        int startJ = 0;
        int walkable = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    startI = i;
                    startJ = j;
                }
                if (grid[i][j] != -1)
                    walkable++;
            }
        }
        return traverse(grid, startI, startJ, 0, walkable);
    }
};