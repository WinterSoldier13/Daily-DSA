#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

class Solution
{
private:
    unordered_multiset<string> hashset;
    void helper(string str, int start, int end)
    {
        while (start >= 0 and end < str.size() and (str[start] == str[end]))
        {
            hashset.insert(str.substr(start, end - start + 1));
            start--;
            end++;
        }
    }

public:
    vector<string> getGray(string S)
    {
        hashset.clear();

        for (int i = 0; i < S.size(); i++)
        {
            helper(S, i, i);
            helper(S, i, i + 1);
        }
        vector<string> out;
        for (auto it = hashset.begin(); it != hashset.end(); it++)
        {
            out.push_back(*it);
        }
        return out;
    }
};

int main()
{
    string s = "geeksforgeeksskeegrofskeeg";

    Solution ob;

    for (auto x : ob.getGray(s))
        cout << x << " ";
    cout << endl;
    return 0;
}