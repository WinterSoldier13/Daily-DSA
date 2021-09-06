class Solution {
public:
    int subtractProductAndSum(int n) 
    {
        int temp = n;
        
        long long int pr=1;
        long long int sum_ = 0;
        
        while(temp>0)
        {
            pr*=(temp%10);
            temp/=10;
        }
        while(n>0)
        {
            sum_+=(n%10);
            n/=10;
        }
        return pr-sum_;
        
    }
};