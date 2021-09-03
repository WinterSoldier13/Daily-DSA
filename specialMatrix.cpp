
#define MOD 1000000007
class Solution {
public:
	int FindWays(int n, int m, vector<vector<int>>blocked_cells){
	    vector<vector<int>> arr(n, vector<int> (m,1));
	    
	    for(auto x: blocked_cells)
	    {
	        arr[x[0]-1][x[1]-1] = 0;
	        if(x[0] ==1 and x[1] == 1)
	        {
	            return 0;
	        }
	    }
	    
	    vector<vector<int>> dp(n, vector<int> (m,0));
	    
	    dp[0][0] = 1;
	    
	    for(int i=0;i<m;i++)
	    {
	        if(arr[0][i] == 1)
	        {
	            dp[0][i] = 1;
	        }
	        else
	        {
	            break;
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i][0] == 1)
	        {
	            dp[i][0] = 1;
	        }
	        else
	        {
	            break;
	        }
	    }
	    
	    for(int i=1;i<n;i++)
	    {
	        for(int j=1;j<m; j++)
	        {
	            if(arr[i][j] != 0)
	            {
	                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
	            }
	        }
	    }
	    
	    return dp[n-1][m-1]%MOD;
	    
	}
};