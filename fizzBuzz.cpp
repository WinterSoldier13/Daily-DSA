class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> out;
        
        for(int i=1;i<=n;i++)
        {
            if(i%3==0 and i%5==0)
                out.push_back("FizzBuzz");
            else if(i%3==0)
                out.push_back("Fizz");
            else if(i%5==0)
                out.push_back("Buzz");
            else
                out.push_back(to_string(i));
        }
        return out;
        
    }
};