class Solution {
public:
    unordered_map<int, int> hashmap;
    int fib(int N) 
    {
        if(hashmap.find(N) != hashmap.end())
        {
            return hashmap[N];
        }
        if(N==0)
        {
            return hashmap[N] =0;
        }
        if(N==1)
        {
            return hashmap[N] = 1;
        }
        
        return hashmap[N] = fib(N-1) + fib(N-2);
        
    }
};