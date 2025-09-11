// sorting

#include <iostream>

using namespace std;

class Solution
{
public:
    string sortVowels(string s)
    {
        bool isVowel[256] = {false};
        for (char v : {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'})
            isVowel[(unsigned char)v] = true;
        int freq[256] = {0};
        for (char i : s)
        {
            if (isVowel[(int)i])
            {
                freq[(int)i]++;
            }
        }
        int j = 0;
        for (char &i : s)
        {
            if (isVowel[(int)i])
            {
                while (!freq[j])
                    ++j;
                i = char(j);
                freq[j]--;
            }
        }
        return s;
    }
};