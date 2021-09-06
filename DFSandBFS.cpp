#include<iostream>
#include <bits/stdc++.h> 

using namespace std; 

// ________________________________________________________________________________________________________


unordered_map<int, vector<int>>  makeGraph(vector<vector<int>> &edges, int n)
{
    unordered_map<int, vector<int> > grid;
    for (auto x: edges)
    {
        grid[x[0]].push_back(x[1]);
        // grid[x[1]].push_back(x[0]); // Uncomment to make non directed graph
    }

    vector<vector<int>> gridV;
    for(int i=1;i<=n;i++)
    {
        vector<int> temp{i};
        for(auto x: grid[i])
        {
            temp.push_back(x);
        }
        gridV.push_back(temp);

    }

    return grid;
}

void printGraph(vector<vector<int>> &graph, int n)
{
    for(auto x: graph)
    {
        for(int c:x)
        {
            cout<<c<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
// ________________________________________________________________________________________________________



// ITERATIVE DFS _________________________________________________________________________________

void DFS(unordered_map<int, vector<int>> graph, int n)
{
    stack<int> stack;
    unordered_set<int> hashset;

    stack.push(1);

    while(!stack.empty())
    {
        int current = stack.top();
        stack.pop();

        if(hashset.find(current) == hashset.end())
        {
            hashset.insert(current);
            cout<<current<<" ";
        }
        for(int connection: graph[current])
        {
            if(hashset.find(connection) == hashset.end())
            stack.push(connection);
        }
    }
}

// _______________________________________________________________________________________________________





void recursiveDFShelper(unordered_map<int, vector<int>> &graph, int n, unordered_set<int> &visited)
{
    visited.insert(n);
    cout<<n<<" ";

    for(auto x: graph[n])
    {
        if(visited.find(x) == visited.end())
        {
            recursiveDFShelper(graph, x, visited);
        }
    }

}

void recursiveDFS(unordered_map<int, vector<int>> &graph)
{
    unordered_set<int> visited;
    recursiveDFShelper(graph, 1, visited);
}


// __________________________________________________________________________________________________________________________


void recursiveTopohelper(unordered_map<int, vector<int>> &graph, int n, unordered_set<int> &visited, stack<int> &stack)
{
    visited.insert(n);
    

    for(auto x: graph[n])
    {
        if(visited.find(x) == visited.end())
        {
            recursiveTopohelper(graph, x, visited, stack);
        }
    }

    stack.push(n);

}

void recursiveTopo(unordered_map<int, vector<int>> &graph, int n)
{
    stack<int> stack;

    unordered_set<int> visited;

    for(int i=1;i<=n;i++)
    {
        if(visited.find(i) == visited.end())
        {
            recursiveTopohelper(graph,i,visited,stack);
        }
    }

    while(!stack.empty())
    {
        cout<<stack.top()<<" ";
        stack.pop();
    }

}

// ___________________________________________________________________________________________________________________


void BFS(unordered_map<int, vector<int>> graph, int n)
{
    queue<int> q;
    unordered_set<int> hashset;

    q.push(1);

    while(!q.empty())
    {
        int current = q.front();
        q.pop();

        if(hashset.find(current) == hashset.end())
        {
            hashset.insert(current);
            cout<<current<<" ";
        }
        for(int connection: graph[current])
        {
            if(hashset.find(connection) == hashset.end())
            q.push(connection);
        }
    }
}

// ________________________________________________________________________________________________________

bool detectCycle(unordered_map<int, vector<int>> graph, int n)
{
    queue<int> q;
    unordered_set<int> hashset;

    q.push(1);

    while(!q.empty())
    {
        int current = q.front();
        q.pop();

        if(hashset.find(current) == hashset.end())
        {
            hashset.insert(current);
            // cout<<current<<" ";
        }
        for(int connection: graph[current])
        {
            if(hashset.find(connection) == hashset.end())
            q.push(connection);
            else
            {
                return true;
            }
            
        }
    }
    return false;
}

// ________________________________________________________________________________________________________



int main()
{
    int n =4;
    vector<vector<int>> arr{{1,2},
                            {1,3},
                            {2,3},
                            
                            {3,4}
    };
                            

    unordered_map<int,vector<int>> graph = makeGraph(arr, n);

    DFS(graph, n);
    cout<<endl;

    recursiveDFS(graph);
    cout<<endl;

    BFS(graph, n);
    cout<<endl; 
    
    recursiveTopo(graph, n);
    cout<<endl;

    cout<<detectCycle(graph, n)<<endl;
    

    
    return 0;
}