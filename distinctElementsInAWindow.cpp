#include</home/wintersoldier/Desktop/test/pycpp.cpp>
#include<bits/stdc++.h>
using namespace std;

utils ob;

vector <int> countDistinct (int A[], int n, int k) 
{
    unordered_map<int, int> hashmap;

    for(int i=0;i<k;i++)
    {
        hashmap[A[i]]++;
    }
    vector<int> distinctEle;
    distinctEle.push_back(hashmap.size());

    for(int i=k;i<n;i++)
    {
        int prevEle = A[i-k];
        int nextEle = A[i];

        hashmap[prevEle]--;

        if(hashmap[prevEle] == 0)
        hashmap.erase(prevEle);

        hashmap[nextEle]++;

        distinctEle.push_back(hashmap.size());

    }
    return distinctEle;

    
}