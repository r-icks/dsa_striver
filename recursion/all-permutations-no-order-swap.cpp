// math
// vector

// time complexity -> n!

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void permuteR(vector<vector<int>> &result, vector<int> &nums, int fixed = 0)
    {
        int n = nums.size();
        if (fixed == n)
        {
            result.push_back(nums);
            return;
        }

        for (int i = fixed; i < n; i++)
        {
            swap(nums[fixed], nums[i]);
            permuteR(result, nums, fixed + 1);
            swap(nums[fixed], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        permuteR(ans, nums);
        return ans;
    }
};