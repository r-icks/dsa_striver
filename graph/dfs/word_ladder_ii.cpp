// bfs
// dfs
// graph
// word

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<vector<string>> answer;
    unordered_map<string, vector<string>> reverseGraph;

    void dfs(vector<string> &path, string beginWord)
    {
        if (path.back() == beginWord)
        {
            vector<string> temp(path.rbegin(), path.rend());
            answer.push_back(temp);
            return;
        }

        for (string &next : reverseGraph[path[path.size() - 1]])
        {
            path.push_back(next);
            dfs(path, beginWord);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        int len = beginWord.size();
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end())
            return answer;

        queue<string> q;
        q.push(beginWord);
        wordSet.erase(beginWord);

        bool foundEnd = false;

        while (!q.empty() && !foundEnd)
        {
            int sz = q.size();
            unordered_set<string> wordUsed;

            while (sz--)
            {
                string word = q.front();
                q.pop();
                for (int i = 0; i < len; i++)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        string new_word = word;
                        new_word[i] = 'a' + j;
                        if (wordSet.find(new_word) != wordSet.end())
                        {
                            reverseGraph[new_word].push_back(word);
                            if (wordUsed.find(new_word) == wordUsed.end())
                            {
                                q.push(new_word);
                                wordUsed.insert(new_word);
                            }
                            if (new_word == endWord)
                                foundEnd = true;
                        }
                    }
                }
            }

            for (string i : wordUsed)
                wordSet.erase(i);
        }
        vector<string> path;
        path.push_back(endWord);
        dfs(path, beginWord);
        return answer;
    }
};