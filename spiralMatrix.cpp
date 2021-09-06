#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& arr) 
    {
        vector<int> out;
        int rows = arr.size();
        int cols = arr[0].size();
        
        int start1=0, end1=cols;
        int start2=1, end2=rows;
        int start3=cols-2, end3=-1;
        int start4=rows-2, end4 = 0;
        
        int row1 = 0;
        int col1 = cols-1;
        int row2 = rows-1;
        int col2 = 0;
        
        while(out.size()<rows*cols)
        {
            
            //1st move
            for(int i=start1;i<end1;i++)
            {
                out.push_back(arr[row1][i]);
            }
            row1++;
            start1++;
            end1--;
            
            if(out.size()==rows*cols)
                break;
            
            //2nd move
            for(int i=start2;i<end2;i++)
            {
                out.push_back(arr[i][col1]);
            }
            col1--;
            start2++;
            end2--;
            
            if(out.size()==rows*cols)
                break;
            
            //3rd move
            for(int i = start3;i>end3;i--)
            {
                out.push_back(arr[row2][i]);
            }
            row2--;
            start3--;
            end3++;
            
            if(out.size()==rows*cols)
                break;
            
            //4th move
            for(int i=start4; i>end4;i--)
            {
                out.push_back(arr[i][col2]);
            }
            col2++;
            start4--;
            end4++;
        }
        return out;
        
    }

int main()
{
    vector<vector<int>> arr{{1,2,3,4,5},
                             {6,7,8,9,10},
                             {11,12,13,14,15},
                             {16,17,18,19,20},
                             {21,22,23,24,25}};
    for(auto c: spiralOrder(arr))
    {
        cout<<c<<endl;
    }

    return 0;
}