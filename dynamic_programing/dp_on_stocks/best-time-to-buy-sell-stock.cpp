// dp

#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int max_profit = 0;
        int lowest = prices[0];
        for (int i = 0; i < prices.size(); i++)
        {
            lowest = min(lowest, prices[i]);
            max_profit = max(max_profit, prices[i] - lowest);
        }
        return max_profit;
    }
};