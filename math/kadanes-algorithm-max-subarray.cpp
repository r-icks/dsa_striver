// kadane's algorithm
// vector
// math

#include <vector>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = nums[0];
        int curSum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (curSum < 0)
                curSum = 0;
            curSum = curSum + nums[i];
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};