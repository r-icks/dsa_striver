// greedy
// comparator

#include <iostream>

using namespace std;

class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        vector<pair<int, int>> greedy;
        for (int it = 0; it < costs.size(); it++)
        {
            auto &i = costs[it];
            int dif = i[1] - i[0];
            greedy.push_back(make_pair(dif, it));
        }

        sort(greedy.begin(), greedy.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.first < b.first; });

        int total_cost = 0;

        for (int i = 0; i < costs.size() / 2; i++)
        {
            total_cost += costs[greedy[i].second][1] + costs[greedy[costs.size() - i - 1].second][0];
        }
        return total_cost;
    }
};