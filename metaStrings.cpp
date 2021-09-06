#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        string s1;
        string s2;

        cin>>s1>>s2;

        int differences = 0;

        int l1 = s1.size();
        int l2 = s2.size();

        if(l1 != l2)
        {
            printf("0\n");
            continue;
        }
        bool flag = true;
        unordered_map<char, int> hashmap;
        for(auto x: s1)
        {
            hashmap[x]++;
        }

        for(auto x:s2 )
        {
            if(hashmap.find(x) == hashmap.end())
            {
                flag = false;
                break;
            }
            else
            {
                hashmap[x]--;
                if(hashmap[x] == 0)
                {
                    hashmap.erase(x);
                }
            }
        }

        if(!flag)
        {
            printf("0\n");
            continue;
        }

        for(int i = 0; i<l1;i++)
        {
            if(s1[i]!=s2[i])
            {
                differences++;
            }
        }

        if(differences==2)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
        
    }
}
