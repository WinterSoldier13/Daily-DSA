#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<int, int>

void smallerOnLeft(int arr[], int N)
{
    set<int> s;
    
    for(int i = 0; i < N; i++)
    {
        auto itr = s.lower_bound(arr[i]);
        
        if(itr != s.begin())
        {
            cout << *(--itr) << " ";
        }
        else
        {
            cout << "-1 ";
        }
        
        s.insert(arr[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while(T--)
    {
        int N;
        cin >> N;
        
        int arr[N];
        for(int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        
        smallerOnLeft(arr, N);
		cout << "\n";
    }
    return 0;
}
