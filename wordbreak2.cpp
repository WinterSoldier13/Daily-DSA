#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<lli, int>

class Solution
{
public:
    vector<vector<string>> mothership;
    void recurse(string s, unordered_set<string> &hashset, vector<string> &path)
    {
        int l = s.size();
        if(l <= 0)
        {
            mothership.push_back(path);
            return;
        }

        for(int i=0;i<=l;i++)
        {
            string front = s.substr(0, i);
            string back = s.substr(i, l-i);

            // cout<<front<<endl;
            if(hashset.count(front))
            {
                path.push_back(front);
                recurse(back, hashset, path);
                path.pop_back();
            }
        }
    }

    string trim(string s)
    {
        int l = s.size();
        string temp = "";
        for(int i=0;i<l-1;i++)
        {
            temp+=s[i];
        }
        return temp;
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        vector<string> out;
        unordered_set<string> hashset;
        for(auto x: wordDict)
        {
            hashset.insert(x);
        }
        vector<string> path;

        recurse(s, hashset, path);

        for(auto x: mothership)
        {
            string temp = "";
            for(auto c: x)
            {
                temp+=c;
                temp+=" ";
            }
            if(temp[temp.size() - 1] == ' ')
            {
                temp = trim(temp);
            }
            out.push_back(temp);
        }
        return out;
    }
};


class Solution2
{
    map<string, vector<string>> mem;

    vector<string> recurse(string s, unordered_set<string> &hashset)
    {
        if(mem.find(s) != mem.end())
        {
            return mem[s];
        }
        vector<string> out;
        if(hashset.find(s) != hashset.end())
        {   
            out.push_back(s);
        }

        for(int i=0;i<s.size();i++)
        {
            string front = s.substr(0,i);

            if(hashset.find(front) != hashset.end())
            {
                string back = s.substr(i, s.size() -i);

                for(auto str : recurse(back, hashset))
                {
                    out.push_back(front+" "+str);
                }
            }
        }
        mem[s] = out;
        return out;
    }
}
int main()
{
    fast_cin();
    cin.tie(0);
    cout.tie(0);

    Solution ob;
    string s = "pineapplepenapple";
    vector<string> wordDict{"apple", "pen", "applepen", "pine", "pineapple"};

    vector<string> out = ob.wordBreak(s, wordDict);
    for(auto x: out)
    {
        cout<<x<<endl;
    }
}