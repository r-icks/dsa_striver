// segment tree

#include <iostream>

using namespace std;

class NumArray
{
public:
    vector<int> segmentTree;
    int n;

    void buildSegmentTree(vector<int> &nums, int ulim, int llim, int node)
    {
        if (ulim == llim)
        {
            segmentTree[node] = nums[llim];
            return;
        }
        int left_node = node * 2 + 1;
        int right_node = node * 2 + 2;
        int m = (ulim + llim) / 2;
        buildSegmentTree(nums, m, llim, left_node);
        buildSegmentTree(nums, ulim, m + 1, right_node);
        segmentTree[node] = segmentTree[left_node] + segmentTree[right_node];
    }

    void updateSegmentTree(int node, int ulim, int llim, int index, int value)
    {
        if (ulim == llim && index == ulim)
        {
            segmentTree[node] = value;
            return;
        }
        if (index < llim || index > ulim || llim >= ulim)
            return;
        int left_node = node * 2 + 1;
        int right_node = node * 2 + 2;
        int m = (ulim + llim) / 2;
        updateSegmentTree(left_node, m, llim, index, value);
        updateSegmentTree(right_node, ulim, m + 1, index, value);
        segmentTree[node] = segmentTree[left_node] + segmentTree[right_node];
    }

    int getSegmentSum(int node, int ulim, int llim, int left, int right)
    {
        if (right < llim || left > ulim)
            return 0;
        if (left <= llim && right >= ulim)
            return segmentTree[node];
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        int m = (llim + ulim) / 2;
        int result = getSegmentSum(left_node, m, llim, left, right) +
                     getSegmentSum(right_node, ulim, m + 1, left, right);
        return result;
    }

    void update(int index, int val)
    {
        updateSegmentTree(0, n - 1, 0, index, val);
    }

    NumArray(vector<int> &nums)
    {
        n = nums.size();
        segmentTree.assign(4 * n, 0);
        buildSegmentTree(nums, n - 1, 0, 0);
    }

    int sumRange(int left, int right)
    {
        return getSegmentSum(0, n - 1, 0, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */