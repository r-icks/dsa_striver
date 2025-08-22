// stack
// dp
// grid

#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int numSubmat(vector<vector<int>> &mat)
    {
        int rows = mat.size();
        int cols = mat[0].size();
        int submatrices = 0;
        int ans = 0;
        vector<int> height(cols, 0);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (mat[i][j] == 1)
                {
                    height[j] += 1;
                }
                else
                {
                    height[j] = 0;
                }
            }

            stack<int> increasing_height;
            vector<int> area_sum(cols, 0);
            for (int j = 0; j < cols; j++)
            {
                while (!increasing_height.empty() && height[increasing_height.top()] >= height[j])
                    increasing_height.pop();
                if (increasing_height.empty())
                {
                    area_sum[j] = height[j] * (j + 1);
                }
                else
                {
                    int last_height = increasing_height.top();
                    area_sum[j] = area_sum[last_height] + height[j] * (j - last_height);
                }
                increasing_height.push(j);
                ans += area_sum[j];
            }
        }
        return ans;
    }
};