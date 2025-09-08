// math
// popcount
// bit manipulation
// builtin
// greedy

#include <iostream>

using namespace std;

class Solution
{
public:
    bool nKpowerOf2(long long n, int k)
    {
        // popcount of n -> number of bits in n should be <= k (number of power of 2)
        return __builtin_popcountll(n) <= k;
        // 2nd condition is that n should be >= k if k>n, then terminate
    }
    int makeTheIntegerZero(int num1, int num2)
    {
        int k = 1;
        while (true)
        {
            long long n = num1 - 1LL * k * num2;
            if (k > n)
            {
                return -1;
            }
            if (nKpowerOf2(n, k))
            {
                return k;
            }
            k++;
        }
        return -1;
    }
};