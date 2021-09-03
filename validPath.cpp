#include<iostream>
#include <bits/stdc++.h> 

using namespace std; 


vector<vector<int>> grid;
vector<pair<int, int>> cords;
int R;

void init(int x, int y)
{
	vector<int> temp(x, 0);

	for(int i=0;i<y;i++)
	{
		grid.push_back(temp);
	}
}

void printGrid()
{
	for (auto x: grid)
	{
	for(int c: x)
	cout<<c<<" ";
	cout<<endl;
	}
}

bool isNotBlock(int x, int y)
{
	for(pair<int,int> p: cords)
	{
		int xC = p.first -1 ;
		int yC = p.second -1 ;

		int dis = sqrt(pow(abs(x-xC) , 2) + pow(abs(y-yC),2) );
		
		if(dis<=R)
		{
			return false;
		}

	}
	return true;

}

bool move(int x, int y, int currentX, int currentY)
{

	
	if( currentX>=x or currentY>=y or currentX<0 or currentY<0 or !isNotBlock(currentX, currentY) or grid[currentX][currentY]== -1)
	{
		return false;
	}
	if(currentX == x-1 and currentY == y-1 and isNotBlock(currentX, currentY))
	{
		return true;
	}

	grid[currentX][currentY] = -1;
	return (
	move(x,y, x-1,y) or
	move(x,y, x-1,y+1) or
	move(x,y, x,y+1) or
	move(x,y, x+1,y+1) or
	move(x,y, x+1,y) or
	move(x,y, x+1,y-1) or
	move(x,y, x,y-1) or
	move(x,y, x-1,y-1)
	);


}



int validPath(int x, int y, int n, int r, vector<int> &xCord, vector<int> &yCord)
{
	
	for(int i=0;i<n;i++)
	{
		cords.push_back(make_pair(xCord[i], yCord[i]));
	}
	init(x,y);
	R = r;

	return move(x,y,0,0);


}

int main()
{
	vector<int> x{1,3};
	vector<int> y{3,3};
	int res = validPath(5,5,2,1,x,y);

	cout<<res<<endl;
	printGrid();
	return 0;
}


