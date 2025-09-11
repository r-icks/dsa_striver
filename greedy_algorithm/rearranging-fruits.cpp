// greedy
// map
// two pointers

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    long long minCost(vector<int> &basket1, vector<int> &basket2)
    {
        map<int, int> freq;
        int m = INT_MAX;
        for (int i : basket1)
        {
            freq[i]++;
            m = min(i, m);
        }
        for (int i : basket2)
        {
            freq[i]--;
            m = min(i, m);
        }
        long long ans = 0;
        auto first = freq.begin();
        auto last = prev(freq.end());
        while (first->first < last->first)
        {
            int smallEle = first->first;
            int count1 = abs(first->second);
            int count2 = abs(last->second);
            if (count1 % 2 != 0 || count2 % 2 != 0)
                return -1;
            int mini = min(count1, count2);
            if (mini != 0)
            {
                first->second = abs(first->second) - mini;
                last->second = abs(last->second) - mini;
                ans += 1LL * min(2 * m, smallEle) * (mini / 2);
            }
            if (first->second == 0)
                first = next(first);
            if (last->second == 0)
                last = prev(last);
        }
        if (first->first == last->first)
        {
            ans += 1LL * min(2 * m, first->first) * (abs(first->second) / 4);
        }
        return ans;
    }
};