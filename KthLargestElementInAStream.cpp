class KthLargest {
public:
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int K;
    
    KthLargest(int k, vector<int>& nums) 
    {
        K = k;
        
        for(auto x: nums)
        {
            minHeap.push(x);
        }
        while(minHeap.size()>k)
        {
            minHeap.pop();
        }
        
        
    }
    
    int add(int val) 
    {
        minHeap.push(val);
        
        if(minHeap.size()>K)
        {
            minHeap.pop();
        }
        return minHeap.top();
        
    }
};
