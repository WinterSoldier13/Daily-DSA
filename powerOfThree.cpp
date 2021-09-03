class Solution {
public:
    bool isPowerOfThree(int N) 
    {
        
        double n = N;
        
        while(n>0)
        {
            if(n==1)
            {
                return true;
            }
            n/=3;
        }
        return false;
        
    }
};