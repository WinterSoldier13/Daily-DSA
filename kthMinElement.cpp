#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    int t;
    cin>>t;
    for(int z =1;z<=t;z++)
    {
        int n;
        cin>>n;

        priority_queue<int, vector<int>, greater<int>> hashset;

        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            hashset.push(temp);
        }
        int k;
        cin>>k;
        int count =0;
        // auto it = hashset.begin();

        while(count++<k-1)
        {
            hashset.pop();
        }
        cout<<hashset.top()<<endl;


    }

}