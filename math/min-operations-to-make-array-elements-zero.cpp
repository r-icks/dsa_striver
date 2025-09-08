// math
// bit manipulation
// summation
// builtin

#include <iostream>

using namespace std;

class Solution
{
public:
    using ll = long long;
    ll ops(int i)
    {
        return (i + 1) / 2;
    }

    // Full Group -> till the last bit, everything can be covered so we can simply calculate ∑ceil(i/2)*2^(i-1)
    // ysin
    ll fullGroups(int m)
    {
        if (m <= 0)
            return 0;
        int b = m / 2;
        ll sum = (1LL - (ll)(b + 1) * ((ll)1 << (2 * b)) + (ll)b * ((ll)1 << (2 * b + 2))) / 3;
        if (m % 2 == 1)
        {
            sum += (ll)(b + 1) * ((ll)1 << (2 * b));
        }
        return sum;
    }
    ll get(int n)
    {
        if (n <= 0)
            return 0;
        int k = 32 - __builtin_clz(n);
        ll result = fullGroups(k - 1);
        ll tail = n - ((1 << (k - 1))) + 1;
        result += ops(k) * tail;
        return result;
    }
    long long minOperations(vector<vector<int>> &queries)
    {
        ll res = 0;
        for (auto &q : queries)
        {
            res += (get(q[1]) - get(q[0] - 1) + 1) / 2;
        }
        return res;
    }
};