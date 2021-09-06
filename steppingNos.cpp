#include<iostream>
#include<bits/stdc++.h>

using namespace std;



void bfs(int start, int end, int num)
{
    queue<int> q;
    q.push(num);

    while(!q.empty())
    {
        int current = q.front();
        q.pop();

        if(current<=end and current>=start)
        {
            cout<<current<<endl;
        }
        if(current>end)
        {
            break;
        }
        
        int lastDigit = current%10;
        if(lastDigit!=9 and lastDigit!=0)
        {
            q.push(current*10 + lastDigit -1);
            q.push(current*10 + lastDigit +1);
        }
        else if(lastDigit==0)
        {
            q.push(current*10+1);
        }
        else if(lastDigit==9)
        {
            q.push(current*10+8);
        }

    }

}

void displayStepping(int start, int end)
{
    for(int i= 1;i<=9;i++)
    {
        bfs(start, end, i);
    }
}


int main()
{
    int start =10;
    int end =20;
    displayStepping(start, end);

    return 0;
}