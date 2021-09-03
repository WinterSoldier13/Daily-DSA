#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        int n;
        cin>>n;
        pair<int,int> t;
        vector<pair<int,int>> timings(n,t);
        for(int i=0;i<n;i++)
        {
            string temp;
            cin>>temp;
            timings[i].first = stoi(temp);
        }
        for(int i=0;i<n;i++)
        {
            string temp;
            cin>>temp;
            timings[i].second = stoi(temp);
        }
        
        sort(timings.begin(), timings.end());
        vector<pair<int, int>> platforms;

        for(int i=0;i<n;i++)
        {
            int arrival = timings[i].first;
            int departure  = timings[i].second;
            
            if(platforms.size() == 0)
            {
                platforms.push_back(make_pair(arrival, departure));
                continue;
            }
            else
            {
                int l = platforms.size();
                bool flag= true;
                for(int j=0;j<l;j++)
                {
                    pair<int,int> platform = platforms[j];
                    if(arrival>platform.second)
                    {
                        platforms[j].first = arrival;
                        platforms[j].second = departure;
                        flag = false;
                        break;
                    }
                }
                if(flag)
                {
                    platforms.push_back(make_pair(arrival, departure));
                }
            }
            
        }
        cout<<platforms.size()<<endl;


    }
}