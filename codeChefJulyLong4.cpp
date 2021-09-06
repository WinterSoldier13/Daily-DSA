#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        cin>>n;

        set<ll> x,y;

        for(int i=0;i<4*n-1;i++)
        {
            ll a,b;
            cin>>a>>b;

            // You can also use x.find(a)
            if(x.count(a))
            {
                x.erase(a);
            }
            else
            {
                x.insert(a);
            }
            
            if(y.count(b))
            {
                y.erase(b);
            }
            else
            {
                y.insert(b);
            }
            
        }
        cout<<(*x.begin())<<" "<<(*y.begin())<<endl;

    }
}