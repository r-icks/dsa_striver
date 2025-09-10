// bitset
// greedy

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int minimumTeachings(int lang, vector<vector<int>> &languages, vector<vector<int>> &friendships)
    {
        int friends = languages.size();
        unordered_set<int> cannot_communicate;
        for (auto friendship : friendships)
        {
            bitset<501> knows;
            for (int language : languages[friendship[0] - 1])
            {
                knows[language] = 1;
            }
            bool communicate = false;
            for (int language : languages[friendship[1] - 1])
            {
                if (knows[language])
                {
                    communicate = true;
                    break;
                }
            }
            if (!communicate)
            {
                cannot_communicate.insert(friendship[0] - 1);
                cannot_communicate.insert(friendship[1] - 1);
            }
        }
        int max_count = 0;
        vector<int> counts(lang, 0);
        for (int i : cannot_communicate)
        {
            for (int language : languages[i])
            {
                max_count = max(max_count, ++counts[language - 1]);
            }
        }
        return cannot_communicate.size() - max_count;
    }
};