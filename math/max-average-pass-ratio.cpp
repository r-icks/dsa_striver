// math
// average
// heap
// priority queue
// lambda

#include <iostream>

using namespace std;

class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        auto cmp = [](const pair<double, int> &a, const pair<double, int> &b)
        {
            return a.first < b.first;
        };
        priority_queue<pair<double, int>, vector<pair<double, int>>, decltype(cmp)> maxHeap(cmp);
        for (int it = 0; it < classes.size(); it++)
        {
            auto &i = classes[it];
            double delta = (double)(i[0] + 1) / (i[1] + 1) - (double)i[0] / i[1];
            maxHeap.push(make_pair(delta, it));
        }
        while (extraStudents--)
        {
            pair<double, int> maxp = maxHeap.top();
            maxHeap.pop();
            auto &i = classes[maxp.second];
            i[0]++;
            i[1]++;
            double delta = (double)(i[0] + 1) / (i[1] + 1) - (double)i[0] / i[1];
            maxHeap.push(make_pair(delta, maxp.second));
        }
        double ans = 0;
        for (int it = 0; it < classes.size(); it++)
        {
            auto &i = classes[it];
            ans += (double)i[0] / i[1];
        }
        return ans / classes.size();
    }
};