// two pointer

#include <vector>

using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int ans = 0;
        bool count0 = false;
        while (right < n)
        {
            if (nums[right])
            {
                right++;
            }
            else
            {
                if (!count0)
                {
                    right++;
                }
                else
                {
                    while (nums[left] != 0)
                    {
                        left++;
                    }
                    left++;
                    right++;
                }
                count0 = true;
            }
            ans = max(ans, right - left - count0);
        }
        return ans == n ? n - 1 : ans;
    }
};