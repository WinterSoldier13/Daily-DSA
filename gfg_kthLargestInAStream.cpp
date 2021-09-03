#include<bits/stdc++.h>
// #include</home/wintersoldier/Desktop/test/pycpp.cpp>
using namespace std;


int main()
{
    // utils ob;
    int t;
    cin>>t;

    while(t--)
    {
        int k,n;
        cin>>k>>n;

        priority_queue<int,vector<int>, greater<int>> minHeap;
        for(int i=0;i<n;i++)
        {
            int inp;
            cin>>inp;

            minHeap.push(inp);

            if(minHeap.size()<k)
            {
                cout<<-1<<" ";
            }
            else if(minHeap.size()==k)
            {
                cout<<minHeap.top()<<" ";
            }
            else
            {
                minHeap.pop();
                cout<<minHeap.top()<<" ";
            }
            
        }
        cout<<endl;
    }
}