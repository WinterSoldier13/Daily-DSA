#include<bits/stdc++.h>
using namespace std;



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;


        vector<long long int> arr1(k, 0);
        vector<long long int> arr2(k, 0);

        for(int i=0;i<k;i++)
        cin>>arr1[i];
        for(int i=0;i<k;i++)
        cin>>arr2[i];

        if(arr1.size()!=arr2.size())
        {
            cout<<0<<endl;
            continue;
        }


        unordered_map<long long int, int> hashmap;

        for(long long int x: arr1)
        hashmap[x]++;

        bool flag = true;
        for(long long int x: arr2)
        {
            if(hashmap.find(x) == hashmap.end())
            {
                flag = false;
                break;
            }
            else
            {
                if(hashmap[x]>0)
                {
                    hashmap[x]--;
                    if(hashmap[x] == 0)
                    hashmap.erase(x);
                }

            }
            
        }

        if(flag)
        cout<<1<<endl;
        else
        {
            cout<<0<<endl;
        }
        


        
    }
}