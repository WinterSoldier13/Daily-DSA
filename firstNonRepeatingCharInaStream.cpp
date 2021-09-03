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
        vector<char> arr(n,' ');

        queue<char> q;
        vector<int> hashmap(256, 0);

        for(int i=0;i<n;i++)
        {
            char ch;
            cin>>ch;
            hashmap[ch]++;
            q.push(ch);
            if(i == 0)
            {
                cout<<ch<<" ";
                q.push(ch);
                continue;
            }

            while(!q.empty() and hashmap[q.front()]>1)
            {
                q.pop();
            
            }
            if(q.empty())
            cout<<-1<<" ";

            else
            {
                cout<<q.front()<<" ";
            }
            
        }
        cout<<endl;
    }
}