class Solution {
public:
    int countPrimes(int n) {
        
        int count = 0;
        
        for (int i = 2; i < n; i++)
        {
            if (isPrime(i) == true)
                count++;
        }
        
        return count;
    }
    
    bool isPrime(int num)
    {
        bool primeNum = true;
        
        if (num <= 1) return false;
        
        for (int i = 2; i*i <= num; i++)
        {
            
            if (i == num)
            {
                continue;
            }
            
            if (num % i == 0)
            {
                primeNum = false;
                break;
            }    
        }
        
        return primeNum;
        
    }
};