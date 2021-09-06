class Solution {
public:
    int countCharacters(vector<string>& words, string chars)
    {
        int count=0;
        if(words.size() == 0 or chars.size()==0)
        {
            return 0;
        }
        
        unordered_map<char, int> hashmap;
        
        for(auto ch: chars)
            hashmap[ch]++;
        
        unordered_map<char, int> temp= hashmap;
        
        for(auto x: words)
        {
            temp = hashmap;
            bool flag = true;
            
            for(auto c:x)
            {
                if(temp.find(c)!=temp.end() and temp[c]>0)
                {
                    temp[c]--;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                count+=x.size();
                cout<<x<<endl;
            }
                
        }
        return count;
        
    }
};
