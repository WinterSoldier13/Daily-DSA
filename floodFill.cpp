#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void recurse(vector<vector<int>> &image, int i, int j, int oldColor, int newColor)
{
    int rows = image.size();
    int cols = image[0].size();
    cout<<i<<" "<<j<<endl;
    
    if(i<0 or j<0 or i>=rows or j>=cols or image[i][j]!=oldColor)
    {
        return;
    }
    
    image[i][j] = newColor;
    recurse(image,i-1,j,oldColor,newColor);
    recurse(image,i,j-1,oldColor,newColor);
    recurse(image,i+1,j,oldColor,newColor);
    recurse(image,i,j+1,oldColor,newColor);
    
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
{
    int oldColor = image[sr][sc];
    cout<<"OLD: "<<oldColor<<endl;
    if(oldColor==newColor)
    {
        return image;
    }
    recurse(image,sr,sc,oldColor,newColor);
    return image;
    
}

int main()
{
    vector<vector<int>> img{{0,0,0},{0,1,1}};

    for(auto x: floodFill(img, 1,1,1))
    {
        for(auto c:x)
        {
            cout<<c<<" ";
        }
        cout<<endl;
    }
}