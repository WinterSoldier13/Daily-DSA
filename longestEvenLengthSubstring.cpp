#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

int expandFromCenter(string &s, int ptr)
{
    int ptr1 = ptr;
    int ptr2 = ptr+1;
    int leftSum = 0;
    int rightSum = 0;
    int max_ = 0;
    while(ptr1>=0 and ptr2<s.size())
    {
        leftSum+= (s[ptr1]-'0');
        rightSum+= (s[ptr2]-'0');

        if(leftSum == rightSum)
        {
            max_ = max(max_, ptr2-ptr1+1);
        }
        ptr1--;
        ptr2++;
    }
    return max_;
}
void solve(string s)
{
    int max_= 0;
    if(s.size() == 0)
    {
        cout<<0<<endl;
        return;
    }
    int localMax = 0;
    for(int i=0;i<s.size()-1;i++)
    {
        localMax = expandFromCenter(s, i);
        max_ = max(max_, localMax);
    }
    cout<<max_<<endl;
    return;
}

int main()
{
    cin.tie(NULL);

    int t;
    cin>>t;

    while (t--)
    {
        string s;
        cin>>s;

        solve(s);
    }
    
    return 0;
}