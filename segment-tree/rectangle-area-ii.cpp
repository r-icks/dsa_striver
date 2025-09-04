// sweep line
// segment tree
// geometric sweep
// tuple
// coordinate compression

#include <iostream>
#include <map>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> countSeg;
    vector<int> lengthSeg;
    vector<int> coords;
    map<int, int> yIndex;

    void updateSeg(int node, int ulim, int llim, int u, int l, int type)
    {
        if (l >= ulim || u <= llim)
            return;
        int left_node = node * 2 + 1;
        int right_node = node * 2 + 2;
        if (ulim <= u && llim >= l)
        {
            countSeg[node] += type;
        }
        else
        {
            int m = (ulim + llim) / 2;
            updateSeg(left_node, m, llim, u, l, type);
            updateSeg(right_node, ulim, m, u, l, type);
        }

        if (countSeg[node] > 0)
        {
            lengthSeg[node] = coords[ulim] - coords[llim];
        }
        else if (ulim - llim == 1)
        {
            lengthSeg[node] = 0;
        }
        else
        {
            lengthSeg[node] = lengthSeg[left_node] + lengthSeg[right_node];
        }
    }

    int rectangleArea(vector<vector<int>> &rectangles)
    {
        long long area = 0;
        const int MOD = 1e9 + 7;
        vector<tuple<int, int, int, int>> events;
        vector<int> all_y;
        for (int i = 0; i < rectangles.size(); i++)
        {
            auto &rec = rectangles[i];
            events.emplace_back(rec[0], rec[1], rec[3], 1);
            events.emplace_back(rec[2], rec[1], rec[3], -1);
            // note - y index is like [y1,y2) because for 0,2 we take square on 0 and on 1
            all_y.push_back(rec[1]);
            all_y.push_back(rec[3]);
        }
        sort(all_y.begin(), all_y.end());
        all_y.erase(unique(all_y.begin(), all_y.end()), all_y.end());
        coords = all_y;
        for (int i = 0; i < coords.size(); i++)
        {
            yIndex[coords[i]] = i;
        }

        int ind = coords.size();
        countSeg.assign(4 * ind, 0), lengthSeg.assign(4 * ind, 0);
        sort(events.begin(), events.end());
        for (int i = 0; i < events.size(); i++)
        {
            auto [x, y1, y2, type] = events[i];
            if (i > 0)
            {
                int prevX = get<0>(events[i - 1]);
                int width = x - prevX;
                long long height = lengthSeg[0];
                area = (area + width * height) % MOD;
            }
            updateSeg(0, ind - 1, 0, yIndex[y2], yIndex[y1], type);
        }

        return area;
    }
};