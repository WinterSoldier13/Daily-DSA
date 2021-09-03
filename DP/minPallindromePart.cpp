#include<iostream>
#include<bits/stdc++.h>

using namespace std;



bool checkPallindrome(string str)
{
    string temp = str;
    reverse(temp.begin(), temp.end());
    return temp==str;
}

static int mem[1001][1001];
void init()
{
    for(int i=0;i<1001;i++)
    {
        for(int j=0;j<1001;j++)
        {
            mem[i][j] = -1;
        }
    }
}



int recursion(string s, int i, int j)
{
    if(mem[i][j]!=-1)
    {
        return mem[i][j];
    }
    if(i>=j)
    {
        return mem[i][j]=0;
    }
    if(checkPallindrome(s.substr(i,j-i+1)))
    {
        return mem[i][j]=0;
    }
    int final_ = INT32_MAX-1;

    for(int k=i;k<j;k++)
    {
        int temp = recursion(s,i,k) + 1 + recursion(s,k+1,j);
        final_ = min(final_ , temp);
    }

    return mem[i][j]=final_;


}

int main()
{
    string str = "nitin";
    init();
    cout<<recursion(str, 0, str.size()-1)<<endl;

    return 0;

}