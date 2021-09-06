#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;

        priority_queue<pair<int, char>> maxHeap;
        unordered_map<char, int> hashmap;

        for(auto x: s)
        {
            hashmap[x]++;
        }
        for(auto it = hashmap.begin();it!=hashmap.end();it++)
        {
            maxHeap.push(make_pair(it->second, it->first));
            // cout<<it->second<<" "<<it->first<<endl;
        }

        priority_queue<pair<int, char>> pq = maxHeap;
        bool flag = false;
        


        int l = s.size();
        string out="";

        int prevUsedCount = -1;
        char prevChar=' ';

        
        while(!maxHeap.empty())
        {
            char currentChar = maxHeap.top().second;

            int val = maxHeap.top().first;

            if(val<=0)
            break;

            maxHeap.pop();

            maxHeap.push(make_pair(prevUsedCount, prevChar));
            prevUsedCount = --val;
            prevChar = currentChar;

            out+=currentChar;

        }
        // cout<<out<<endl;

        if(out.size() == l)
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<0<<endl;
        }

        



    }
}