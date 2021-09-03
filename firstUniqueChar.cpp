class Solution {
public:
    int firstUniqChar(string s) 
    {
        vector<int> track(256, 0);
        
        int l = s.size();
        
        for(int i=0;i<l;i++)
        {
            char ch =s[i];
            track[ch]++;
        }
        for(int i=0;i<l;i++)
            if(track[s[i]]==1)
            return i;
        return -1;
        
    }
};