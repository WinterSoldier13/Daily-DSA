#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli long long int
#define pii pair<int, int>
#define endl '\n'
#define printArr(arr)     \
    for (auto x : arr)    \
        cout << x << " "; \
    cout << endl;
#define printHashmap(hashmap)                                  \
    for (auto it = hashmap.begin(); it != hashmap.end(); it++) \
    {                                                          \
        cout << it->first << " " << it->second << endl;        \
    }
#define print2DArray(arr)     \
    for (auto x : arr)        \
    {                         \
        for (auto c : x)      \
            cout << c << " "; \
        cout << endl;         \
    }

// _______________________________________________________________________________________________________________________________________________________________________________
// _______________________________________________________________________________________________________________________________________________________________________________
// _______________________________________________________________________________________________________________________________________________________________________________


#include <bits/stdc++.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
#define endl "\n"
unordered_map<ll, ll> parent;

ll find(ll s)
{
    if(parent[s] == s)
        return s;
    return parent[s] = find(parent[s]);
}

int main()
{
	fast_cin();

    ll n;
    cin>>n;
    for(ll i = 0; i < n;i++){
        ll x;
        cin>>x;
        parent[x] = x;
    }
    ll edge;
    cin>>edge;
    for(ll i = 0; i < edge;i++){
        ll x,y;
        cin>>x>>y;
        parent[find(x)] = find(y);
    }
    ll a,b;
    cin>>a>>b;
    cout<< (find(a) == find(b))<<endl;
	return 0;
}