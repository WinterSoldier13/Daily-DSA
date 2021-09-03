#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<int, int>

class Solution{
public:	

	// Function to generate a short url from integer ID
	string idToShortURL(long long int n) {
	    string map = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

        string out = "";

        while (n>0)
        {
            int digit = n%62;
            out.push_back(map[digit]);
            n/=62;
        }
        return out;

	}

};


int main()
{
    int V = 3;
    vector<vector<int>> adj{{2, 1}, {0, 1}};

    int c = 0;
    int d = 1;

    Solution ob;
    cout << ob.isBridge(V, adj, c, d) << endl;

    return 0;
}