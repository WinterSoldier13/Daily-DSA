#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> hashmap;

int getPower(int n)
{
    int count=0;
    int temp = n;

    while(n>1)
    {
        if(hashmap.find(n)!=hashmap.end())
        {
            hashmap[temp] = hashmap[n]+ count;
            return hashmap[temp];
        }

        if(n%2==0)
        {
            n= n/2;
        }
        else
        {
            n = 3*n + 1;
        }
        count ++;
    }

    return hashmap[temp] = count;
}


int getKth(int lo, int hi, int k)
{
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    for (int x = lo;x<=hi; x++)
    {
        pq.push(make_pair(getPower(x), x));
    }
    k--;
    while(k--)
    {
        pq.pop();
    }
    return pq.top().second;
}

int main()
{
    cout<<getKth(12,15,2)<<endl;
    return 1;
}