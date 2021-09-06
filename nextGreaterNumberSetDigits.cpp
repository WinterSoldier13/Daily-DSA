#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<lli, int>

int main()
{
    fast_cin();
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;
        int num  =stoi(s);
        sort(s.begin(), s.end());
        bool flag = 0;
        sort(s.begin(), s.end());
        do
        {
            if(stoi(s) > num)
            {
                flag = 1;
                cout<<s<<endl;
                break;
            }
        } while (next_permutation(s.begin(), s.end()));
        

        if(flag == 0)
        {
            cout<<"not possible"<<endl;
        }
    }
}