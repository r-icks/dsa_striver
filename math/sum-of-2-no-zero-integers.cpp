// math
// addition

#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> getNoZeroIntegers(int n)
    {
        int place = 1;
        int num1 = 0;
        int num2 = 0;
        while (n)
        {
            int digit = n % 10;
            switch (digit)
            {
            case 0:
                n -= 10;
                num1 += 1 * place;
                num2 += 9 * place;
                break;
            case 1:
                if (n >= 10)
                {
                    n -= 10;
                    num1 += 2 * place;
                    num2 += 9 * place;
                    break;
                }
            default:
                num1 += (digit - 1) * place;
                num2 += 1 * place;
            }
            place *= 10;
            n /= 10;
        }
        return {num1, num2};
    }
};