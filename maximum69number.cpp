#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) 
    {
        int l = to_string(num).size();
        int maxN = num;

        string strNum = to_string(num);

        for(int i=0;i<l;i++)
        {
            string temp = strNum;
            char ch = strNum[i];
            if(ch=='9')
            {
                temp[i] = '6';
            }
            else
            {
                temp[i] = '9';
            }

            maxN = max(maxN, stoi(temp));
        }
        return maxN;
    }
};