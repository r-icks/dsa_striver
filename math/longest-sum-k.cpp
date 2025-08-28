// prefix sum
// map
// vector

#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int k)
    {
        int longest = 0;
        unordered_map<int, int> mpp;
        int preSum = 0;
        mpp[preSum] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            preSum += nums[i];
            if (mpp.find(preSum - k) != mpp.end())
            {
                longest = max(longest, i - mpp[preSum - k]);
            }
            if (mpp.find(preSum) == mpp.end())
            {
                mpp[preSum] = i;
            }
        }
        return longest;
    }
};