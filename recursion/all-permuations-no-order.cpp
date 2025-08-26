// math
// vector

// time complexity -> n!

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void permuteR(vector<vector<int>> &result, vector<int> &store, vector<int> &nums, vector<bool> &occurs)
    {
        int n = nums.size();
        if (store.size() == n)
        {
            result.push_back(store);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (!occurs[i])
            {
                occurs[i] = true;
                store.push_back(nums[i]);
                permuteR(result, store, nums, occurs);
                store.pop_back();
                occurs[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> store;
        store.reserve(nums.size());
        vector<bool> occurs(nums.size(), false);
        permuteR(ans, store, nums, occurs);
        return ans;
    }
};