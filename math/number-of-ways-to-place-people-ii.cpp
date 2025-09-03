// math
// graph
// sorting

#include <iostream>

using namespace std;

class Solution
{
public:
    int numberOfPairs(vector<vector<int>> &points)
    {
        auto cmp = [](const vector<int> &point1, const vector<int> &point2)
        {
            if (point1[0] < point2[0])
                return true;
            if (point1[0] > point2[0])
                return false;
            return point1[1] > point2[1];
        };
        sort(points.begin(), points.end(), cmp);
        int count = 0;
        for (int id = 0; id < points.size() - 1; id++)
        {
            auto &i = points[id];
            int min_y = INT_MIN;
            for (int jd = id + 1; jd < points.size(); jd++)
            {
                auto &j = points[jd];
                if (j[1] > i[1])
                    continue;
                if (j[1] <= min_y)
                    continue;
                min_y = max(j[1], min_y);
                count++;
            }
        }
        return count;
    }
};