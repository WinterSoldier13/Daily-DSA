#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    vector<vector<string>> out;
    unordered_map<string, vector<string>> hashmap;

    for(auto x: string_list)
    {
        string temp = x;
        sort(temp.begin(), temp.end());
        hashmap[temp].push_back(x);
    }
    for(auto it = hashmap.begin(); it!=hashmap.end() ; it++)
    {
        out.push_back(it->second);
    }
    return out;
}