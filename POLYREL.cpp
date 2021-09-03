#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int
#define tiii tuple<int, int, int, int>

int main()
{
    int t;
    scanf("%d", &t);
    int n, k;
    vector<lli> arr(100001);
    for(int i=0;i<=5;i++)
    {
        arr[i] = 0;
    }
    arr[6]=3;
    arr[7]=3;
    int count = 1;
    for(int i=8;i<100001;i++)
    {
        if(count == 1)
        {
            arr[i] = arr[i-1]+1;
            count++;
        }
        else if(count == 2)
        {
            arr[i] = arr[i-1];
            count = 1;
        }
    }


    while (t--)
    {
        cin>>n;
        for(int i=0;i<2*n;i++)
        {
            int temp;
            cin>>temp;
        }
        if(n<=5)
        {
            cout<<n<<endl;
            continue;
        }

        int sum_ = n;

        int val = arr[n];

        while (val!=0)
        {
            sum_+=val;
            val = arr[val];
        }
        cout<<sum_<<endl;
    }
}
