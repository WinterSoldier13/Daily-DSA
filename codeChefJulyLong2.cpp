#include<bits/stdc++.h>
using namespace std;

long long int power(long long int n)
{
    long long int sum_ = 0;
    while (n>0)
    {
        int d=n%10;
        sum_+=d;
        n/=10;
    }
    return sum_;
    
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        vector<long long int> stackA;
        vector<long long int> stackB;
        int chef, morty;

        for(int i=0;i<n;i++)
        {
            cin>>chef;
            stackA.push_back(chef);
            cin>>morty;
            stackB.push_back(morty);
        }

        long long int chefPoints=0, mortyPoints = 0;

        for(int i=0;i<n;i++)
        {
            long long int c = power(stackA[i]);
            long long int m = power(stackB[i]);

            if(c==m)
            {
                chefPoints+=1;
                mortyPoints+=1;
            }
            else if(c>m)
            {
                chefPoints++;
            }
            else
            {
                mortyPoints++;
            }
            
        }
        
        if(chefPoints>mortyPoints)
        {
            cout<<0<<" "<<chefPoints<<endl;
        }
        else if(chefPoints<mortyPoints)
        {
            cout<<1<<" "<<mortyPoints<<endl;
        }
        else
        {
            cout<<2<<" "<<chefPoints<<endl;
        }
        
    }
}