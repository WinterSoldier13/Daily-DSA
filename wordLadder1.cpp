#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solve(string beginWord, string endWord, vector<string> &wordList)
{

    set<string> hashset;

    for (auto x : wordList)
    {
        hashset.insert(x);
    }
    if (hashset.find(endWord) == hashset.end())
        return 0;

    queue<string> q;

    q.push(beginWord);
    int level = 0;

    while (!q.empty())
    {
        ++level;

        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            string current = q.front();
            q.pop();

            int l = current.size();
            for (int i = 0; i < l; i++)
            {
                char originalChar = current[i];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    if (ch == current[i])
                        continue;
                    current[i] = ch;

                    if (current == endWord)
                    {
                        return level + 1;
                    }
                    else if (hashset.find(current) != hashset.end())
                    {
                        q.push(current);
                        hashset.erase(current);
                    }
                }
                current[i] = originalChar;
            }
        }
    }
    return 0;
}
