#include<bits/stdc++.h>
using namespace std;

int tour(petrolPump p[],int n)
{
    vector<int> cap;
    vector<int> nextDis;

    for(int i=0;i<n;i++)
    {
        auto x = p[i];
        cap.push_back(x.petrol);
        nextDis.push_back(x.distance);
    }

    int remaining=0;
    int startIndex=0;
    int totalDistanceToBeTravelled = 0;
    int totalGasAvailable = 0;
    for(int i=0;i<n;i++)
    {
        int c = cap[i];
        int d = nextDis[i];

        remaining+=(c-d);

        if(remaining<0)
        {
            startIndex = i+1;
            remaining = 0;
        }

        totalDistanceToBeTravelled+=d;
        totalGasAvailable+=c;
    }
    if(totalDistanceToBeTravelled>totalGasAvailable)
    return -1;
    return startIndex;
}
