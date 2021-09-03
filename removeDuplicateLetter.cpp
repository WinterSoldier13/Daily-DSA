#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int
#define tiii tuple<int, int, int, int>

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        if (s.size() == 0 or s.size() == 1)
        {
            return s;
        }

        unordered_map<char, int> hashmap;
        for (auto x : s)
        {
            hashmap[x]++;
        }
        unordered_set<char> track;

        stack<char> stack;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];

            if (stack.empty())
            {
                stack.push(ch);
                hashmap[ch]--;
                track.insert(ch);
                continue;
            }
            if (track.count(ch))
            {
                hashmap[ch]--;
                continue;
            }
            while (!stack.empty() and (stack.top()) > ch and (hashmap[stack.top()] > 0))
            {
                char top = stack.top();
                track.erase(top);
                stack.pop();
            }
            stack.push(ch);
            hashmap[ch]--;
            track.insert(ch);
        }
        string t = "";
        while (!stack.empty())
        {
            t += stack.top();
            stack.pop();
        }
        reverse(t.begin(), t.end());
        return t;
    }
};

int main()
{
    string s = "bbcaac";
    Solution ob;
    cout << ob.removeDuplicateLetters(s) << endl;
}2