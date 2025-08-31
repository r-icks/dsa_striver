// math

#include <algorithm>
using namespace std;

class Solution
{
public:
    int mcn(int m, int n)
    {
        long long ans = 1;
        for (int i = 1; i <= n; i++)
        {
            ans *= (m - i + 1);
            ans /= i;
        }
        return ans;
    }
    int uniquePaths(int m, int n)
    {
        if (m < n)
            swap(m, n);
        return mcn(m + n - 2, n - 1);
    }
};