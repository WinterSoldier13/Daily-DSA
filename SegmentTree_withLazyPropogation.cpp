#include <bits/stdc++.h>
using namespace std;
#define fast_cin()                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL)
#define ll int
#define endl "\n"
#include <stdio.h>
#include <math.h>




#define MAX 1000
  
int SegmentTree[MAX] = {0};  // To store segment SegmentTree
int lazy[MAX] = {0};  // To store pending updates
  

void updateRangeUtil(int si, int ss, int se, int us, int ue, int diff)
{
    if (lazy[si] != 0)
    {
        SegmentTree[si] += (se-ss+1)*lazy[si];
        if (ss != se)
        {
            lazy[si*2 + 1]   += lazy[si];
            lazy[si*2 + 2]   += lazy[si];
        }
        lazy[si] = 0;
    }
  
    if (ss>se || ss>ue || se<us)
        return ;
    if (ss>=us && se<=ue)
    {
        SegmentTree[si] += (se-ss+1)*diff;

        if (ss != se)
        {
            lazy[si*2 + 1]   += diff;
            lazy[si*2 + 2]   += diff;
        }
        return;
    }
    int mid = (ss+se)/2;
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);
    SegmentTree[si] = SegmentTree[si*2+1] + SegmentTree[si*2+2];
}
  
void updateRange(int n, int us, int ue, int diff)
{
   updateRangeUtil(0, 0, n-1, us, ue, diff);
}
  
  

int getSumUtil(int ss, int se, int qs, int qe, int si)
{
    if (lazy[si] != 0)
    {
        SegmentTree[si] += (se-ss+1)*lazy[si];
        if (ss != se)
        {
            lazy[si*2+1] += lazy[si];
            lazy[si*2+2] += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss>se || ss>qe || se<qs)
        return 0;

    if (ss>=qs && se<=qe)
        return SegmentTree[si];

    int mid = (ss + se)/2;
    return getSumUtil(ss, mid, qs, qe, 2*si+1) + getSumUtil(mid+1, se, qs, qe, 2*si+2);
}
  
int getSum(int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
    return getSumUtil(0, n-1, qs, qe, 0);
}
  
void constructSTUtil(int arr[], int ss, int se, int si)
{
    if (ss > se)
        return ;
    if (ss == se)
    {
        SegmentTree[si] = arr[ss];
        return;
    }
  
    int mid = (ss + se)/2;
    constructSTUtil(arr, ss, mid, si*2+1);
    constructSTUtil(arr, mid+1, se, si*2+2);
  
    SegmentTree[si] = SegmentTree[si*2 + 1] + SegmentTree[si*2 + 2];
}
  

void constructST(int arr[], int n)
{
    constructSTUtil(arr, 0, n-1, 0);
}
  

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
  
    constructST(arr, n);
  
    printf("Sum of values in given range = %d\n",
           getSum(n, 1, 3));
  
    // Add 10 to all nodes at indexes from 1 to 5.
    updateRange(n, 1, 5, 10);
  
    // Find sum after the value is updated
    printf("Updated sum of values in given range = %d\n", getSum( n, 1, 3));
  
    return 0;
}