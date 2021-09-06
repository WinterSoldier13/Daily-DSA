#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

int main()
{
    fast_cin();
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin>>n;

        string out = "";
        int sum_ = 0;
        int count = 0;
        while(n>0)
        {
            int ch = n&1;

            if(count%2!=0 and ch)
            {
                sum_+=pow(2, count);
            }
            count++;
            n = n>>1;
        }
        cout<<sum_<<endl;
    }
}