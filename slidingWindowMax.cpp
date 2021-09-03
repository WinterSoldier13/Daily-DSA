class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) 
    {
        int l = arr.size();
        deque<int> dq;
        vector<int> out;
        if(arr.size()==0)
            return out;
        if(arr.size()==1 or k==1)
        {
            return arr;
        }
        
        // Okay so the Idea is that initially for the first K elements... I will keep their max. in the dq
        for(int i=0;i<k;i++)
        {
            if(dq.empty())
            {
                dq.push_back(i);
            }
            while(!dq.empty() and arr[dq.back()]<=arr[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        for(int i=k;i<arr.size();i++)
        {
            //The front of the dq is the largest element for this set of Window
            out.push_back(arr[dq.front()]);
            
            int currentElement = arr[i];
            
            //Okay so now Again I'll remove all the elements in the dq which are smaller than myy current ele
            while(!dq.empty() and arr[dq.back()]<currentElement)
            {
                dq.pop_back();
            }
            
            //This time removing back ele is not enough... as there may be elements in the front of the dq...which are the oldest and
            //have now come out of the window... Then we need to remove that ele also
            while(!dq.empty() and dq.front()+k<=i)
            {
                dq.pop_front();
            }
            //At last put the ele index
            dq.push_back(i);
        }
        out.push_back(arr[dq.front()]); // The last window ele remains
        
        return out;
        
        
        
    }
};