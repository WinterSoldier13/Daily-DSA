class Solution {
public:

void gameOfLife(vector<vector<int>>& board) 
{
    int rows = board.size();
    int cols = board[0].size();

    vector<vector<int>> arr = board;

    for(int i=0;i<rows;i++)
    {

        for(int j=0;j<cols;j++)
        {
            int current = arr[i][j];

            int count = 0;

            if(i-1>=0)
            if(board[i-1][j])
            count++;
            
            if(i-1>=0 and j+1<cols)
            if(board[i-1][j+1])
            count++;
            
            if(j+1<cols)
            if(board[i][j+1])
            count++;
            
            if((i+1)<rows and j+1<cols)
            if(board[i+1][j+1])
            count++;

            if(i+1<rows)
            if(board[i+1][j])
            count++;

            if(i+1<rows and j-1>=0)
            if(board[i+1][j-1])
            count++;

            if(j-1>=0)
            if(board[i][j-1])
            count++;

            if(i-1>=0 and j-1>=0)
            if(board[i-1][j-1])
            count++;

            if(current == 1 and count<2)
            arr[i][j] = 0;

            if(current == 1 and (count==2 or count==3))
            arr[i][j] = 1;

            if(current == 1 and count>3)
            arr[i][j] = 0;

            if(current==0 and count == 3)
            arr[i][j] = 1;

            cout<<count<<" ";

        }
        cout<<endl;
    }  
    cout<<endl;

    for(auto x: arr)
    {
        for(auto c:x)
        cout<<c<<" ";
        cout<<endl;
    }  
    
    board = arr;
}

};