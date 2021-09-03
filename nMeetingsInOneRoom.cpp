#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        vector<int> start(n,0);
        vector<int> end_(n,0);
        for(int i=0;i<n;i++)
        cin>>start[i];
        for(int i=0 ;i<n;i++)
        cin>>end_[i];

        // vector<int> start{1,3,0,5,8,5};
        // vector<int>  end_{2,4,6,7,9,9};
        // int n = 6;

        vector<pair<int, int>> slots;
        for (int i=0;i<n;i++)
        {
            slots.push_back(make_pair(end_[i], start[i]));
        }
        start.clear();
        end_.clear();
      
        unordered_map<string, int> hashmap;
        int i=0;
        for(auto x: slots)
        {
            string startTime = to_string(x.first);
            string endTime   = to_string(x.second);

            hashmap[startTime+endTime] = i++;
            
        }

        sort(slots.begin(), slots.end());

        for(int i=0;i<slots.size();i++)
        {
            int alpha = slots[i].first;
            slots[i].first = slots[i].second;
            slots[i].second = alpha;
        }


        vector<pair<int,int >> rooms;

        for(auto slot: slots)
        {
            if(rooms.size()==0)
            {
                rooms.push_back(slot);
                continue;
            }
            if(slot.first<=rooms[rooms.size()-1].second)
            {
                continue;
            }
            else
            {
                rooms.push_back(slot);
            }
            
        }
        vector<string> out;

        for(auto x: rooms)
        {
            // cout<<x.first<<" "<<x.second<<" || ";
            out.push_back(to_string(x.second)+to_string(x.first));
        // }cout<<endl;
        for (auto x: out)
        {
            cout<<hashmap[x]+1<<" ";
        }
        cout<<endl;

    }
}