// vector
// dp

#include <vector>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int col0 = matrix[0][0];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (j == 0)
                    {
                        col0 = 0;
                    }
                    else
                        matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                int row = matrix[i][0];
                int col = matrix[0][j];
                if (row == 0 || col == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < cols; j++)
                matrix[0][j] = 0;
        }
        if (col0 == 0)
        {
            for (int i = 0; i < rows; i++)
                matrix[i][0] = 0;
        }
    }
};