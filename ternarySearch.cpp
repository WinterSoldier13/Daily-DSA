#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

int ternarySearch(int arr[], int N, int K) 
{ 
    
    int start = 0;
    int end = N-1;
    
    while(start<=end)
    {
        int mid1 = start + (end-start)/3;
        int mid2 = end - (end-start)/3;
        
        if(K == arr[mid1])
        {
            return 1;
        }
        if( K == arr[mid2])
        {
            return 1;
        }
        if(K < arr[mid1])
        {
            end = mid1 -1;
        }
        else if(  K > arr[mid2])
        {
            start = mid2 + 1;
        }
        else
        {
            start = mid1 + 1;
            end = mid2 - 1;
        }
    }
   
   return -1;
}

int main()
{
    fast_cin();
    cin.tie(NULL);

    return 0;
}