#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct boardNode
{
    int node;
    int distance;
};

void printBoard(vector<int> &arr)
{
    for(auto x: arr)
        {
            cout<<x<<" ";
        }
        cout<<endl;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        vector<int> temp(2*n, 0);
        for(int i=0;i<2*n;i++)
        {
            cin>>temp[i];
            temp[i]--;
        }

        vector<int> board(30 , -1);

        for(int i=0;i<temp.size();i+=2)
        {
            board[temp[i]] = temp[i+1];
        }


        printBoard(board);

        boardNode firstNode;
        firstNode.distance=0;
        firstNode.node = 0;

        queue<boardNode> q;
        vector<int> visited(30, 0);

        q.push(firstNode);
        visited[0] = 1;

        boardNode curr;

        while(!q.empty())
        {
            curr = q.front();
            q.pop();

            int currNode = curr.node;
            // cout<<currNode<<endl;
            if(curr.node == 29)
            {
                break;
            }

            for(int j = currNode+1;j<=currNode+6 and j<30;j++)
            {
                if(visited[j] == 0)
                {
                    visited[j] = 1;

                    boardNode nextNode;
                    nextNode.distance = curr.distance + 1; // It will not be +j as we can roll the dice to 1,2,3,4,5,6
                    

                    if(board[j] == -1)
                    {
                        nextNode.node = j;
                    }
                    else
                    {
                        nextNode.node = board[j];
                    }
                    q.push(nextNode);
                }
            }
        }
        cout<<curr.distance<<endl;

        
    }

}
