// math
// vector
// stl

// next_permutation

// write c++ stl code for this

#include <algorithm>
#include <vector>
using namespace std;

// void nextPermutation(vector<int> &nums)
// {
//     next_permutation(nums.begin(), nums.end());
// }

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        if (nums.size() == 1)
            return;
        int i = nums.size() - 2;
        while (i >= 0)
        {
            if (nums[i] < nums[i + 1])
            {
                break;
            }
            i--;
        }
        if (i >= 0)
        {
            int j = i + 1;
            for (; j < nums.size(); j++)
            {
                if (nums[j] <= nums[i])
                {
                    break;
                }
            }
            j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};