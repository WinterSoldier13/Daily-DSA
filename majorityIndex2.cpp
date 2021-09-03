class Solution {
public:
    bool checkMajority(vector<int> arr, int index)
    {
        long ele = arr[index];
        int count=0;
        for(long c: arr)
        if(c==ele)
        count++;
        int brick = arr.size()/3;
        if(count>brick)
        {
            return true;
        }
        return false;

    }
    vector<int> majorityVoting(vector<int> &arr)
    {
        int l = arr.size();
        int majorityIndex1 = 0;
        int majorityIndex2 = 0;
        int i = 0;
        int count1 = 0;
        int count2 = 0;
        
        for(i=0;i<l;i++)
        {
            if(arr[i] == arr[majorityIndex1])
                count1++;
            else if(arr[i] == arr[majorityIndex2])
                count2++;
            else if(count1 == 0)
            {
                majorityIndex1 = i;
                count1++;
            }
            else if(count2 == 0)
            {
                majorityIndex2 = i;
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        vector<int> out;
        if(arr[majorityIndex1] == arr[majorityIndex2])
        {
            if(checkMajority(arr, majorityIndex1))
            out.push_back(arr[majorityIndex1]);
        }
        else
        {
            if(checkMajority(arr, majorityIndex1))
            out.push_back(arr[majorityIndex1]);
            if(checkMajority(arr, majorityIndex2))
            out.push_back(arr[majorityIndex2]);
            
        }
        return out;
    }
    
    vector<int> majorityElement(vector<int>& nums) 
    {
        if(nums.size()==0)
            return nums;
        return majorityVoting(nums);
        
        
    }
};