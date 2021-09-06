class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        
        vector<int> t(n,0);
        vector<vector<int>> arr(n,t);
        
        unordered_set<int> hashset;
        
        for(int i=0;i<n;i++)
        {
            hashset.insert(i);
        }
        
        for(auto x : trust)
        {
            int p1 = x[0]-1;
            int p2 = x[1]-1;
            
            arr[p1][p2] = 1;
            
            if(hashset.find(p1)!=hashset.end())
            {
                hashset.erase(p1);
            }
            
        }
        
        if(hashset.size() >1 or hashset.size()==0)
        {
            return -1;
        }
        int suspect = *hashset.begin();
        
        bool flag = true;
        
        for(int i=0;i<n;i++)
        {
            if(arr[suspect][i] != 0)
            {
                flag = false;
                break;
            } 
        }
        for(int i=0;i<n;i++)
        {
            if(i!=suspect and arr[i][suspect] != 1)
            {
                flag = false;
                break;
            } 
        }
        
        if(!flag)
        {
            return -1;
        }
        return suspect+1;
    }
};