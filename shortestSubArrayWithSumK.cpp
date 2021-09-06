class Solution {
public:
    
    int shortestSubarray(vector<int>& A, int K) {
        int n=A.size();
        int i;
        vector<int> dp(n+1,0);
        for(i=1;i<=n;i++)
        {
            dp[i]=dp[i-1]+A[i-1];
        }
        deque<int> q;
        int min_len=n+1;
        for(i=0;i<=n;i++)
        {
            while(!q.empty()&&dp[i]-dp[q.front()]>=K)
            {
                min_len=min(min_len,i-q.front());
                q.pop_front();
            }
            while(!q.empty()&&dp[i]-dp[q.back()]<=0)
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        return (min_len==n+1)?-1:min_len;
    }
};