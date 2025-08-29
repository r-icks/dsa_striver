// alic bob flower game
// pnc

using namespace std;

class Solution
{
public:
    long long flowerGame(int n, int m)
    {
        int odd_n = (n + 1) / 2;
        int even_n = n / 2;
        int odd_m = (m + 1) / 2;
        int even_m = m / 2;
        return 1LL * odd_n * even_m + 1LL * even_n * odd_m;
    }
};