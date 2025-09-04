// prefix sum

#include <iostream>

using namespace std;

class NumArray
{
public:
    vector<int> preFixSum;
    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        preFixSum.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            preFixSum.push_back(preFixSum[i - 1] + nums[i]);
        }
    }

    int sumRange(int left, int right)
    {
        return left == 0 ? preFixSum[right] : preFixSum[right] - preFixSum[left - 1];
        return 0;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */