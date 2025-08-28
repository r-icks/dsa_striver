// prefix sum
// vector
// map

#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0;
        unordered_map<int, int> mpp;
        int preSum = 0;
        mpp[preSum]++;
        for (int i = 0; i < nums.size(); i++)
        {
            preSum += nums[i];
            count += mpp[preSum - k];
            mpp[preSum]++;
        }
        return count;
    }
};