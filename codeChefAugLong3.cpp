#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int

int main()
{
    int t;
    scanf("%d", &t);
    
    while (t--)
    {
        int powerChef, powerRick;
        scanf("%d %d", &powerChef, &powerRick);

        lli counta = 0;
        lli countb = 0;

        if(powerChef%9==0)
        {
            counta+=(powerChef/9);
        }
        else
        {
            counta+=(powerChef/9 + 1);
        }
        if(powerRick%9==0)
        {
            countb+=(powerRick/9);
        }
        else
        {
            countb+=(powerRick/9 + 1);
        }

        if(counta>=countb)
        {
            printf("1 %d\n", countb);
        }
        else
        {
            printf("0 %d\n", counta);
        }
        

    }
}
