bool solve(vector<int>& nums) 
{
    int reach = 0;
    int l = nums.size();
    if(l ==0 or l == 1)
    {
        return 1;
    }
    
    for(int i=0;i<l;i++)
    {
        if(i>reach)
        {
            return 0;
        }
        reach = max(reach, i+nums[i]);
        
        if(reach>=l-1)
        {
            return 1;
        }
    }
    return 0;
}