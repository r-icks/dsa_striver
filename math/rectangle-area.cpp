// graph
// math

#include <iostream>

using namespace std;

class Solution
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int left_max = max(ax1, bx1);
        int right_min = min(ax2, bx2);
        int top_min = min(ay2, by2);
        int bot_max = max(ay1, by1);
        int length = right_min - left_max;
        int height = top_min - bot_max;
        return (ay2 - ay1) * (ax2 - ax1) + (bx2 - bx1) * (by2 - by1) - ((length <= 0 || height <= 0) ? 0 : length * height);
    }
};