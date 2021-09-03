class Solution {
public:
    
    vector<vector<int>> mem;
    
    void __init__(int l1,int l2)
    {
        vector<int> t(l2,-1);
        vector<vector<int>> temp(l1,t);
        mem = temp;
    }
    
    int recursion(string s1, string s2, int i, int j)
    {
        if(mem[i][j] != -1)
        {
            return mem[i][j];
        }
        if(i==0)
        {
            return  mem[i][j]=j;
        }
        if(j == 0)
        {
            return  mem[i][j]=i;
        }

        if(s1[i-1] == s2[j-1])
        {
            return  mem[i][j]=recursion(s1,s2,i-1,j-1);
        }

        else
        {
            return  mem[i][j]=1+min(recursion(s1,s2,i-1,j), min(recursion(s1,s2,i,j-1), recursion(s1,s2,i-1,j-1)));
        }

    }

    int minDistance(string s1, string s2) 
    {
        __init__(s1.size()+1, s2.size()+1);
        return recursion(s1,s2,s1.size(),s2.size());
    }
};