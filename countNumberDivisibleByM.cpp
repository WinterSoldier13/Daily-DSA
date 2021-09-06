#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define tiiii tuple<int, int, int, int>
int main()
{
    fast_cin();
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int a, b, m;
        cin>>a>>b>>m;

        int count = 0;

        for(int i=a;i<=b;i++)
        {
            if(i%m == 0)
            {
                count++;
            }
        }
        cout<<count<<endl;
    }
}