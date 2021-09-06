#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int len = s.size();
    vector<char> v;
    for (int i = 0; i < len; i++)
    {
        v.push_back(s.at(i));
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            if (v[j] == 'B' && v[j + 1] == 'G')
            {
                swap(v[j], v[j + 1]);
                j++;
            }
        }
    }
    for (auto x : v)
        cout << x;
}

int main()
{
    //#ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    //freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt
    //freopen("output.txt", "w", stdout);
    //	#endif
    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}