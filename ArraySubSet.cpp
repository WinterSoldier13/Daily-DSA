
// arr[] : the input array
// N : size of the array arr[]

// return the length of the longest subsequene of consecutive integers

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;

        vector<int> arr1(n, 0);
        vector<int> arr2(m, 0);

        for(int i=0;i<n;i++)
        cin>>arr1[i];
        for(int i=0;i<m;i++)
        cin>>arr2[i];

        unordered_map<int, int> hashmap;

        for(int x: arr2)
        hashmap[x]++;

        for(int x: arr1)
        {
            
            if(hashmap.size() == 0)
            {
                break;
            }
            if(hashmap.find(x)!=hashmap.end() and hashmap[x]>0)
            {
                hashmap[x]--;
                
                if(hashmap[x] == 0)
                {
                    hashmap.erase(x);
                }
               
            }

        }
        if(hashmap.size() == 0)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
        

    }
}