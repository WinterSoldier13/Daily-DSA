class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) 
    {
        priority_queue<int> pq;
        for(int x: arr)
            pq.push(x);
        int count=0;
        while(count++<k-1)
        {
            pq.pop();
        }
        return pq.top();
    }
};