#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int

int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        int count = 0;

        for(int i=0;i<32;i++)
        {
            int firstDigitAtEnd = n1&1;
            int secondDigitAtEnd = n2&1;
            if(firstDigitAtEnd != secondDigitAtEnd)
            {
                count++;
            }
            n1 = n1>>1;
            n2 = n2>>1;
        }
        printf("%d\n",count);
    }
}