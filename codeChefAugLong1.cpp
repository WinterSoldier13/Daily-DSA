#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;


int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int h,p;
        scanf("%d %d",&h,&p);
        int flag = 0;
        while(h>0 and p>0)
        {
            h-=p;
            if(h<=0)
            {
                flag=1;
                break;
            }
            p/=2;
            if(p<=0)
            {
                break;
            }
        }
        printf("%d\n",flag);
    }
}
