// dp
// stack

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> increasing_heights;
        int cols = heights.size();
        int max_area = INT_MIN;
        for (int i = 0; i < cols; i++)
        {
            while (!increasing_heights.empty() && heights[increasing_heights.top()] >= heights[i])
            {
                int top_col = increasing_heights.top();
                increasing_heights.pop();
                int l_smaller;
                if (!increasing_heights.empty())
                {
                    l_smaller = increasing_heights.top();
                }
                else
                {
                    l_smaller = -1;
                }
                int area = heights[top_col] * (i - l_smaller - 1);
                max_area = max(area, max_area);
            }
            increasing_heights.push(i);
        }
        while (!increasing_heights.empty())
        {
            int top_col = increasing_heights.top();
            increasing_heights.pop();
            int l_smaller;
            if (!increasing_heights.empty())
            {
                l_smaller = increasing_heights.top();
            }
            else
            {
                l_smaller = -1;
            }
            int area = heights[top_col] * (cols - l_smaller - 1);
            max_area = max(area, max_area);
        }
        return max_area;
    }
};