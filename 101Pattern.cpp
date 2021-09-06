#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<lli, int>

int main()
{
 	fast_cin();
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        bool penDown = false;
        int ptr1 = 0;
        int ptr2 = 0;
        int l = s.size();
        int count = 0;
        
        while(ptr2<l)
        {
            if(s[ptr2] == '1' and penDown == false)
            {
                penDown = true;
                ptr1 = ptr2;
            }
            else if(s[ptr2] == '1' and penDown == true)
            {
                if(ptr2 - ptr1>1)
                {
                    count++;
                }
                ptr1 = ptr2;
            }
            else if(s[ptr2]!='0' and penDown)
            {
                penDown = false;
            }
            ptr2 ++;
        }
        cout<<count<<endl;
    }
	return 0;
}