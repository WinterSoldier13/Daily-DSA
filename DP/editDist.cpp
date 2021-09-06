#include<iostream>
#include <bits/stdc++.h> 
#include<math.h>
using namespace std;


//https://www.interviewbit.com/problems/edit-distance/

//See GeeksForGeeks video for more detailed explanation


int editDis(string A,int i, string B, int j)
{
     if(i==0)
     {
          return j;
     }
     if(j==0)
     {
          return i;
     }
     if(A[i]==B[j])
     {
          return editDis(A,i-1,B,j-1);
     }
     else
     {
          return 1 + min(editDis(A,i,B,j-1)//INSERT
           ,min(editDis(A,i-1,B,j-1),// REPLACE
           editDis(A,i-1,B,j)));   //DELETE
     }
     

}

int recursiveApproch(string A, string B)
{
     
     int l1 = A.length();
     int l2 = B.length();

     int dp[l1+1][l2+1];

     for(int i=0;i<=l2;i++)
     dp[0][i]=i;

     for(int i=0;i<=l1;i++)
     dp[i][0]=i;

     for(int i=1;i<=l1;i++)
     {
          for(int j=1;j<=l2;j++)
          {
               

               if(A[i-1]==B[j-1])
               {
                    dp[i][j]=dp[i-1][j-1];
               }
               else
               {
                    dp[i][j] = 1+ min(dp[i][j-1],min(dp[i-1][j-1], dp[i-1][j]));
               }
               
          }
     }
     return dp[l1][l2];

}



int main()
{
     string A = "bbbaabaa";
     string B = "aababbabb";
     cout<<editDis(A,A.size()-1,B,B.size())<<endl;
     cout<<recursiveApproch(A,B)<<endl;


     return 0;
}