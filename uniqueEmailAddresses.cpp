#include<bits/stdc++.h>
using namespace std;

int numUniqueEmails(vector<string>& emails) 
{
    int l = emails.size();
    unordered_set<string> hashset;

    for(auto x: emails)
    {
        string temp = "";
        int l1 = x.size();
        bool filterEnabled = true;
        int ptr = 0;
        while(ptr<l1)
        {
            char ch = x[ptr];
            if(ch == '@')
            {
                filterEnabled = false;
                ptr++;
                temp+='@';
            }
            else if(filterEnabled and ch=='.')
            {
                ptr++;
            }
            else if(filterEnabled and ch=='+')
            {
                while(x[ptr]!='@')
                {
                    ptr++;
                }
            }
            else
            {
                temp+=ch;
                ptr++;
            }
        }
        // cout<<temp<<endl;
        hashset.insert(temp);
    }
    for(auto it= hashset.begin();it!=hashset.end();it++)
    {
        cout<<*it<<endl;
    }

    return hashset.size();   
}

int main()
{
    // vector<string> emails{"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    vector<string> emails{"test.email+alex@leetcode.com", "test.email@leetcode.com"};
    numUniqueEmails(emails);
}