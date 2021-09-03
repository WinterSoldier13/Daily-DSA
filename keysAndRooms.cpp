#include<iostream>
#include<bits/stdc++.h>

using namespace std;


void dfs(vector<vector<int>> &rooms, int currentRoom, unordered_set<int>& hashset)
{
    for(int roomKey: rooms[currentRoom])
    {
        if(hashset.find(roomKey)!=hashset.end())
        {
            continue;
        }
        else
        {
            hashset.insert(roomKey);
            dfs(rooms, roomKey, hashset);
        }
        
    }

}


bool canVisitAllRooms(vector<vector<int>>& rooms)
{
    unordered_set<int> hashset;
    int l = rooms.size();
    hashset.insert(0);

    dfs(rooms, 0, hashset);
    
    return hashset.size()==l;
}

int main()
{
    vector<vector<int>> arr{{1},{2},{3},{}};
    cout<<canVisitAllRooms(arr)<<endl;
}