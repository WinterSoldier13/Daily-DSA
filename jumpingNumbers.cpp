#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define ll long long int

set<ll> hashset;
void bfs(ll x, ll num) 
{ 
    // Create a queue and enqueue 'i' to it 
    queue<ll> q; 
    q.push(num); 
  
    // Do BFS starting from i 
    while (!q.empty()) { 
        num = q.front(); 
        q.pop(); 
  
        if (num <= x) { 
            hashset.insert(num);
            int last_dig = num % 10; 
  
            // If last digit is 0, append next digit only 
            if (last_dig == 0) 
                q.push((num * 10) + (last_dig + 1)); 
  
            // If last digit is 9, append previous digit only 
            else if (last_dig == 9) 
                q.push((num * 10) + (last_dig - 1)); 
  
            // If last digit is neighter 0 nor 9, append both 
            // previous and next digits 
            else { 
                q.push((num * 10) + (last_dig - 1)); 
                q.push((num * 10) + (last_dig + 1)); 
            } 
        } 
    } 
} 
  
// Prints all jumping numbers smaller than or equal to 
// a positive number x 
void printJumping(ll x) 
{ 
    hashset.insert(0);
    for (int i = 1; i <= 9 && i <= x; i++) 
        bfs(x, i); 
        
    for(auto it= hashset.begin();it!=hashset.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
} 

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        ll n;
        cin >> n;

        printJumping(n);
    }
}