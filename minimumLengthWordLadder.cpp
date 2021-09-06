#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli unsigned long long int
#define pii pair<int, int>

class Solution
{
private:
    vector<vector<string>> mothership;
    int min_;

    void __init__()
    {
        // hashset.clear();
        mothership.clear();
        min_ = INT_MAX;
    }

    void recurse(string start, string end, unordered_set<string> &wordList, vector<string> &path)
    {
        string intermediateWord = start;
        if(path.size() >= min_)
            return;

        if (start == end)
        {
            // mothership.push_back(path);
            min_ = min(min_, (int)path.size());
            return;
        }
        int l = intermediateWord.size();

        for (int i = 0; i < l; i++)
        {
            char currentChar = intermediateWord[i];
            for (auto ch = 'a'; ch <= 'z'; ch++)
            {
                if (ch == currentChar)
                {
                    continue;
                }
                intermediateWord[i] = ch;
                if (wordList.count(intermediateWord))
                {
                    wordList.erase(intermediateWord);
                    path.push_back(intermediateWord);
                    recurse(intermediateWord, end, wordList, path);
                    path.pop_back();
                    wordList.insert(intermediateWord);
                }
            }
            intermediateWord[i] = currentChar;
        }
    }

public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        __init__();
        if (startWord.size() == 0 or startWord.size() != targetWord.size() or startWord == targetWord)
        {
            return 0;
        }
        unordered_set<string> hashset;

        for (auto x : wordList)
        {
            hashset.insert(x);
        }
        // if (hashset.count(startWord) == 0)
        //     return 0;

        vector<string> path;
        path.push_back(startWord);
        if (hashset.count(startWord))
            hashset.erase(startWord);
        recurse(startWord, targetWord, hashset, path);
        
        // for (auto x : mothership)
        // {
        //     min_ = min(min_, (int)x.size());
        // }

        return min_ == INT_MAX ? 0 : min_;
    }
};

int main()
{
    fast_cin();

    vector<string> arr{"hit", "hot", "dot", "dog", "lot", "log", "cog"};
    string s = "hit";
    string e = "cog";

    Solution ob;
    ob.wordLadderLength(s, e, arr);
    return 0;
}