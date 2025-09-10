// bfs
// graph
// tuple

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int len = beginWord.size();
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<tuple<string, int>> q;
        q.emplace(beginWord, 1);
        wordSet.erase(beginWord);
        while (!q.empty())
        {
            auto [word, count] = q.front();
            q.pop();
            for (int i = 0; i < len; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    string new_word = word;
                    new_word[i] = 'a' + j;
                    if (wordSet.find(new_word) != wordSet.end())
                    {
                        if (new_word == endWord)
                        {
                            return count + 1;
                        }
                        q.emplace(new_word, count + 1);
                        wordSet.erase(new_word);
                    }
                }
            }
        }
        return 0;
    }
};