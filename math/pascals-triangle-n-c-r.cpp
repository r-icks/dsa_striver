// math

class Solution
{
public:
    int pascalTriangleI(int r, int c)
    {
        r--;
        c--;
        int ans = 1;
        for (int i = 1; i <= c; i++)
        {
            ans *= (r - i + 1);
            ans /= i;
        }
        return ans;
    }
};