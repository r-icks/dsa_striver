// math
// vector

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> result;
        long long ans = 1;
        result.push_back(ans);
        for (int i = 1; i <= rowIndex; i++)
        {
            ans *= (rowIndex - i + 1);
            ans /= i;
            result.push_back(ans);
        }
        return result;
    }
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++)
        {
            result.push_back(getRow(i));
        }
        return result;
    }
};