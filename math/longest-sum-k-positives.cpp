// sliding window
// two pointer
// vector

#include <vector>

using namespace std;

int longestSubarrayWithSumK(vector<int> nums, long long k)
{
    int left = 0;
    long long curSum = 0;
    int longest = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        curSum += nums[i];
        if (curSum == k)
            longest = max(longest, i - left + 1);
        while (curSum > k)
        {
            curSum -= nums[left++];
            if (curSum == k)
                longest = max(longest, i - left + 1);
        }
    }
    return longest;
}