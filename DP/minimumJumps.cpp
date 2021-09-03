#include<iostream>
#include <bits/stdc++.h> 
#include<math.h>
using namespace std;

//Minimum JUMPS to reach the end of an array


//RECURSIVE APPROACH
int recurse(vector<int> arr, int index)
{
    if(index==arr.size()-1)
    {
        return 0;
    }

    int main_res = arr.size();   // Remember whenever you need to find the min.. from all the branches of a tree do it like this
                                // Declare a variable main_result, then inside the loop find the local_result... then 
                                // Main_result is the min of main_result and the current local result. Finally return main_result.

    for(int i=1;i<=arr[index];i++)
    {
        if(index+i<arr.size())
        {
            int res = 1+recurse(arr,index+i);

            main_res = min(main_res,res);

        }
    }
    return main_res;

}









//DYNAMIC
int dynamic(vector<int> arr)
{
    vector<int> dp(arr.size(),arr.size()+1);
    if(arr.size()==0)
    return 0;
    if(arr.size()==1)
    return 1;
    dp[0] =0;
    dp[1] =1;

    for(int i=2;i<=arr.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(j+arr[j]>=i)
            {
                dp[i] = min(dp[i],1+dp[j]);
            }
        }

    }
    return dp[dp.size()-1];

}


int main()
{
    // vector<int> arr{4,1,5,3,1,3,2,1,8};
    vector<int> arr{0, 46, 46, 0, 2, 47, 1, 24, 45, 0, 0, 24, 18, 29, 27, 11, 0, 0, 40, 12, 4, 0, 0, 0, 49, 42, 13, 5, 12, 45, 10, 0, 29, 11, 22, 15, 17, 41, 34, 23, 11, 35, 0, 18, 47, 0, 38, 37, 3, 37, 0, 43, 50, 0, 25, 12, 0, 38, 28, 37, 5, 4, 12, 23, 31, 9, 26, 19, 11, 21, 0, 0, 40, 18, 44, 0, 0, 0, 0, 30, 26, 37, 0, 26, 39, 10, 1, 0, 0, 3, 50, 46, 1, 38, 38, 7, 6, 38, 27, 7, 25, 30, 0, 0, 36, 37, 6, 39, 40, 32, 41, 12, 3, 44, 44, 39, 2, 26, 40, 36, 35, 21, 14, 41, 48, 50, 21, 0, 0, 23, 49, 21, 11, 27, 40, 47, 49};
    cout<<recurse(arr,0)<<endl;
    cout<<dynamic(arr)<<endl;

    return 0;

}