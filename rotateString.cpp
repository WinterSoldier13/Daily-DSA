class Solution {
public:
    
    string rotateAnti(string s, int n)
    {
        int l = s.size();
        string part2 = s.substr(0, n);
        string part1 = s.substr(n,l-n);

        return part1+part2;

    }
    bool rotateString(string A, string B) 
    {
        int l = A.size();
        if(l==0 and B.size()==0)
            return true;
        if(l==0 or B.size()==0)
            return false;
        if(l!=B.size())
            return false;
        
        for(int i=1;i<=l;i++)
        {
            if(rotateAnti(A,i) == B)
                return true;
        }
        return false;
        
    }
};