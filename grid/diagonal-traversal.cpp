// grid
// traversal

#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int rows = mat.size();
        int cols = mat[0].size();
        bool direction = true;
        vector<int> result;
        int i = 0;
        int j = 0;
        while (true)
        {
            result.push_back(mat[i][j]);
            if ((i == (rows - 1)) && (j == (cols - 1)))
            {
                break;
            }
            if (direction)
            {
                if (j == cols - 1)
                {
                    i++;
                    direction = !direction;
                }
                else if (i == 0)
                {
                    j++;
                    direction = !direction;
                }
                else
                {
                    i--;
                    j++;
                }
            }
            else
            {
                if (i == rows - 1)
                {
                    j++;
                    direction = !direction;
                }
                else if (j == 0)
                {
                    i++;
                    direction = !direction;
                }
                else
                {
                    i++;
                    j--;
                }
            }
        }
        return result;
    }
};