// dp
// traversal
// recursion

#include <vector>

using namespace std;

class Solution
{
public:
    static constexpr int dir_v[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int dp[500][500][4][2];

    int lenDiag(vector<vector<int>> &grid, int i, int j, int dir, bool turn)
    {
        if (dp[i][j][dir][turn] != -1)
        {
            return dp[i][j][dir][turn];
        }
        int target = grid[i][j] == 2 ? 0 : 2;
        int ni = i + dir_v[dir][0];
        int nj = j + dir_v[dir][1];
        if (ni < 0 || ni >= grid.size() || nj < 0 || nj >= grid[0].size() || target != grid[ni][nj])
        {
            return dp[i][j][dir][turn] = 0;
        }
        int ans = 1 + lenDiag(grid, ni, nj, dir, turn);
        if (turn)
        {
            int withTurn = 1 + lenDiag(grid, ni, nj, (dir + 1) % 4, false);
            ans = max(ans, withTurn);
        }
        return dp[i][j][dir][turn] = ans;
    }

    int lenOfVDiagonal(vector<vector<int>> &grid)
    {
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    for (int dir = 0; dir < 4; dir++)
                        ans = max(ans, 1 + lenDiag(grid, i, j, dir, true));
                }
            }
        }
        return ans;
    }
};