#include<bits/stdc++.h>
#include</home/wintersoldier/Desktop/test/pycpp.cpp>
using namespace std;

utils ob;

string frequencySort(string s)
{
    unordered_map<char, int> hashmap;

    for(auto x: s)
    hashmap[x]++;

    priority_queue<pair<int, char>> maxHeap;

    for(auto it= hashmap.begin();it!=hashmap.end();it++)
    {
        maxHeap.push(make_pair(it->second, it->first));
    }
    string newStr ="";

    while(!maxHeap.empty())
    {
        auto curr = maxHeap.top();
        maxHeap.pop();

        int ch = curr.second;
        int count = curr.first;

        while(count--)
        newStr+=ch;
    }
    cout<<newStr;
    return newStr;

}

int main()
{
    string s = "tree";
    frequencySort(s);

}