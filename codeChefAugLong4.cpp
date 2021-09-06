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
        string s1, s2;
        cin>>s1;
        cin>>s2;

        map<char,int> hashmap1;
        
        for(auto x: s1)
        {
            hashmap1[x]++;
        }
        for(auto x: s2)
        {
            hashmap1[x]--;
        }
        string part1="";
        string part2="";
        string part3="";
        int startChar = s2[0];

        for(auto it = hashmap1.begin(); it!=hashmap1.end(); it++)
        {
            for(int i=0;i<it->second;i++)
            {
                if(it->first <startChar)
                {
                    part1+=it->first;
                }
                else if(it->first == startChar)
                {
                    part2+=it->first;
                }
                else
                {
                    part3+=it->first;
                }
            }
        }
        stack<string> stack;
        stack.push(part2+s2);
        int insertLocation = 0;
        for(int i=0;i<part2.size();i++)
        {
            string tempPart1 = part2.substr(0,i);
            string tempPart2 = part2.substr(i,part2.size());

            string newString = tempPart1+s2+tempPart2;
            if(stack.top()>newString)
            {
                stack.pop();
                stack.push(newString);
            }
        }
        part2 = stack.top();

        cout<<part1<<part2<<part3<<endl;
    }
}
