// math
// vector

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        int maxArea = 0;
        int maxDiag = 0;
        for (auto i : dimensions)
        {
            int diag2 = i[0] * i[0] + i[1] * i[1];
            if (diag2 > maxDiag)
            {
                maxArea = i[0] * i[1];
                maxDiag = diag2;
            }
            else if (diag2 == maxDiag)
            {
                maxArea = max(i[0] * i[1], maxArea);
            }
        }
        return maxArea;
    }
};