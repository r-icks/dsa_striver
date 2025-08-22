// grid
// dp
// stack

#include <stack>
#include <vector>
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

                int l_smaller = increasing_heights.empty() ? -1 : increasing_heights.top();
                int area = heights[top_col] * (i - l_smaller - 1);
                max_area = max(area, max_area);
            }
            increasing_heights.push(i);
        }

        while (!increasing_heights.empty())
        {
            int top_col = increasing_heights.top();
            increasing_heights.pop();

            int l_smaller = increasing_heights.empty() ? -1 : increasing_heights.top();
            int area = heights[top_col] * (cols - l_smaller - 1);
            max_area = max(area, max_area);
        }

        return max_area;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);

        int max_area = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                heights[j] = (matrix[i][j] == '0') ? 0 : heights[j] + 1;
            }
            max_area = max(max_area, largestRectangleArea(heights));
        }

        return max_area;
    }
};
