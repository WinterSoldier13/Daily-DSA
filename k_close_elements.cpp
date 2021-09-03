#include<iostream>
#include <bits/stdc++.h> 
#include<math.h>
using namespace std;


// https://leetcode.com/problems/find-k-closest-elements/

vector<int> closestElement(vector<int> arr, int k, int x)
{
    vector<int> distance;
    vector<int> out;
    for(int c: arr)
    {
        distance.push_back(c-x);
    }

    //Now ler's find the mininmum value index in dist
    int min_element= distance[0];
    int min_index =0;
    for(int i=0;i<distance.size();i++)
    {
        if(abs(distance[i])<abs(min_element))
        {
            min_element =abs(distance[i]);
            min_index = i;
        }
    }

    if(min_index == 0)
    {
        while(k)
        {
            out.push_back(arr[min_index]);
            min_index++;
            k--;
        }
        return out;

    }
    else if(min_index== arr.size()-1)
    {
        while (k)
        {
            out.push_back(arr[min_index]);
            min_index--;
            k--;
        }
        sort(out.begin(),out.end());
        return out; 
    }
    else
    {
        out.push_back(arr[min_index]);

        int i = min_index-1;
        int j = min_index+1;

        while(k-1)
        {
            if(abs(distance[i])<=abs(arr[j]))
            {
                out.push_back(arr[i]);
                i--;
            }
            else
            {
                out.push_back(arr[j]);
                j++;
            }
            
        }
        return out;

    }
    
}

int main()  
{  
    vector<int> arr{1,1,1,10,10,10};
    for( int c: closestElement(arr,1,9))
    cout<<c<<endl;    
    return 0;  
}  