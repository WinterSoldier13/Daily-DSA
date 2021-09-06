#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli unsigned long long int
#define pii pair<int, int>

class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
        unordered_map<int, int> hashmap;
        int currentSum = 0;
        vector<int> modSum(n);
        for(int i=0;i<n;i++)
        {
            currentSum+=arr[i];
            modSum[i] = ((currentSum%k)+k)%k;
        }

        int maxL = 0;

        for(int i=0;i<n;i++)
        {
            if(modSum[i] == 0)
            {
                maxL = max(maxL, i+1);
                continue;
            }

            if(hashmap.find(modSum[i]) != hashmap.end())
            {
                maxL = max(maxL, i-hashmap[modSum[i]] +1 );
            }
            else
            {
                hashmap[modSum[i]] = i;
            }
            
        }
        return maxL;
	}
};


int main()
{
    fast_cin();

    return 0;
}