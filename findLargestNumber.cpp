#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli unsigned long long int
#define pii pair<int, int>

class Solution
{
private:


public:
    bool isNonDecreasing(int n)
    {
        int prevD = INT_MAX;

        while (n)
        {
            int d = n%10;
            if(d>prevD)
            {
                return  false;
            }
            prevD = d;
            n/=10;
        }
        return true;
        
    }
    int find(int N)
    {
        while (N)
        {
            if(isNonDecreasing(N))
            {
                return N;
            }
            N--;
        }
        return 0;
    }
};

int main()
{
    fast_cin();

    int n;
    cin>>n;
    Solution ob;
    cout<<ob.find(n)<<endl;
    cout<<ob.isNonDecreasing(69)<<endl;

    return 0;
}