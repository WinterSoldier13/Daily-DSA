#include <bits/stdc++.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

class Solution {
public:
    int trap(vector<int>& arr) 
    {
        int l = arr.size();
        if(l == 0 or l==1) return 0;
        vector<int> left;
        int ans = 0;
        
        left.push_back(arr[0]);
        for(int i=1;i<l;i++)
            left.push_back(max(left.back(), arr[i]));
        int right = arr.back();
        for(int i=l-2;i>=0;i--)
        {
            right = (max(right, arr[i]));
            ans+= (min(left[i], right) - arr[i]);
        }
        return ans;
    }
    int solve(string s)
    {
    	vector<int> arr;
    	int l = s.size();

    	int ptr = 0;
    	string temp = "";
    	while(ptr<l)
    	{
    		if(isdigit(s[ptr]))
    		{
    			while(isdigit(s[ptr]))
    			{
    				temp.push_back(s[ptr]);
    				ptr++;
    			}
    		}
    		else
    		{
    			if(temp!="")
    			{
    				arr.push_back(stoi(temp));
    				temp = "";
    			}
    			ptr++;
    		}
    	}
        if(temp!="")
        {
            arr.push_back(stoi(temp));
            temp = "";
        }
        for(auto x: arr)
            cout<<x<<" ";
        cout<<endl;
    	return trap(arr);
    }
};

int main()
{
	fast_cin();

	string s = "4 2 0 3 2 52";
    Solution ob;
    cout<<ob.solve(s)<<endl;
	return 0;
}