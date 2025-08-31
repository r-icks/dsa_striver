#include <vector>

using namespace std;

// top down
// memoization
// recursion

class Solution
{
public:
    vector<vector<int>> gridDp;
    int solve(vector<vector<int>> &obstacleGrid, int i, int j)
    {
        if (i == obstacleGrid.size() - 1 && j == obstacleGrid[0].size() - 1)
        {
            return !obstacleGrid[i][j];
        }
        if (gridDp[i][j] != -1)
            return gridDp[i][j];
        int ans = 0;
        if (i + 1 < obstacleGrid.size() && !obstacleGrid[i + 1][j])
        {
            ans += solve(obstacleGrid, i + 1, j);
        }
        if (j + 1 < obstacleGrid[0].size() && !obstacleGrid[i][j + 1])
        {
            ans += solve(obstacleGrid, i, j + 1);
        }
        return gridDp[i][j] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        gridDp.assign(m, vector<int>(n, -1));
        if (obstacleGrid[0][0])
            return 0;
        return solve(obstacleGrid, 0, 0);
    }
};

// bottom up

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1])
            return 0;
        vector<long long> lastRow(n, 0);
        lastRow[n - 1] = 1;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (obstacleGrid[i][j])
                {
                    lastRow[j] = 0;
                }
                else if (j < n - 1)
                {
                    lastRow[j] = lastRow[j] + lastRow[j + 1];
                }
            }
        }
        return lastRow[0];
    }
};