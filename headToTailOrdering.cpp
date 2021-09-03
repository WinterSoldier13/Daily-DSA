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

int main()
{
    fast_cin();

    getT()
    {
        int n;
        cin >> n;

        unordered_map<char, int> hashmap;

        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;

            hashmap[s[0]]++;
            hashmap[s[s.size() - 1]]++;
        }
        int countOfVertexWithOddDegree = 0;

        for (auto it = hashmap.begin(); it != hashmap.end(); it++)
        {
            if(it->second % 2 != 0)
            {
                countOfVertexWithOddDegree++;
            }
            if(countOfVertexWithOddDegree > 2)
            {
                break;
            }
        }
        if(countOfVertexWithOddDegree <=2)
        {
            cout<<"Head to tail ordering is possible."<<endl;
        }
        else
        {
            cout<<"Head to tail ordering is not possible."<<endl;
        }
        
    }
    return 0;
}