// sliding window
// dp

#include <vector>
using namespace std;

class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        int MOD = 1e9 + 7;
        vector<int> knows(n, -1);
        knows[0] = 1; // on zeroth day -> 1 person knows the secret
        int currentDay = 1;
        long long canShareCount = 0;
        while (currentDay < n)
        {
            int new_add_day = currentDay - delay;
            int new_forget_day = currentDay - forget;
            if (new_add_day >= 0)
                canShareCount = (canShareCount + knows[new_add_day]) % MOD;
            if (new_forget_day >= 0)
                canShareCount = (canShareCount - knows[new_forget_day] + MOD) % MOD;
            knows[currentDay++] = canShareCount;
        }
        int ans = 0;
        for (int i = n - forget; i < n; i++)
        {
            ans = (0LL + ans + knows[i]) % MOD;
        }
        return ans;
    }
};