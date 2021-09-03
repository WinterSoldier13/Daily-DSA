class Solution {
public:
    int findComplement(int num) 
    {
        int  sum_ = 0;
        int index =0 ;
        
        while(num)
        {
            int lastDigit = num&1;
            num = num>>1;
            
            if(lastDigit)
            {
                index++;
            }
            else
            {
                sum_+=pow(2,index);
                index++;
            }
        }
        return sum_;
        
    }
};