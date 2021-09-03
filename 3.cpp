#include<iostream>
#include <bits/stdc++.h> 
#include<math.h>
using namespace std;

// https://www.interviewbit.com/problems/n3-repeat-number/

bool checkMajority(vector<int> arr, int index)
{
    long ele = arr[index];
    int count=0;
    for(long c: arr)
    if(c==ele)
    count++;
    int brick = arr.size()/3;
    if(count>=brick)
    {
        return true;
    }
    return false;

}

int repeatNumber(const vector<int> &arr)
{
    int l = arr.size();
    cout<<l<<endl;
    int brick = l/3;
    cout<<brick<<endl;
    int majority1_index =0;
    int majority2_index =0;
    int count1=0;
    int count2=0;

    for(int i=0;i<l;i++)
    {
        if(arr[i]==arr[majority1_index])
        {
            count1++;
        }
        else if(arr[i]==arr[majority2_index])
        {
            count2++;
        }


        else if(count1==0)
        {
            majority1_index=i;
            count1++;
        }
        else if(count2==0)
        {
            majority2_index = i;
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
        
    }

    if (checkMajority(arr,majority1_index))
    {
        cout<<arr[majority1_index]<<endl;
        cout<<arr[majority2_index]<<endl;
        return arr[majority1_index];
    }
    else if(checkMajority(arr,majority2_index))
    {
        return arr[majority2_index];
    }
    return -1;


}



int main()  
{  
    vector<int> arr{1,1,1,3,3,2,2,2};
    cout<< repeatNumber(arr)<<endl;
    return 0;  
}  