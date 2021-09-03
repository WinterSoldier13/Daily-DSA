bool isCyclicHelper(vector<int> g[], vector<int> &visited, int source) {
    //for(int i = 0; i < V; i++) cout << visited[i] << " ";
    //cout << endl;
    queue<int> q;
    q.push(source); 
    visited[source] = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        visited[node] = 1;
        for(const auto &i : g[node]) {
            if(visited[i] == -1) {
                visited[i] = 0;
                q.push(i);
            //if visited[i] == 0. It means, i(current vertex) is already in under processing mode
            //And we found once again the vertex that means there is a Cycle
            //in the Graph
            }else if(visited[i] == 0)
                return true;
        }
    }
    
    return false;
}


bool isCyclic(vector<int> g[], int V)
{
	/* 
		1 --> visited/processed or popped out from the queue
		0 --> visited/under processing mode or still present in queue
		-1 --> unvisited so far.
	*/
    vector<int> visited(V, -1);
    for(int i = 0; i < V; i++) {
        if(visited[i] == -1) {
            if(isCyclicHelper(g, visited, i))
                return true;
        }
    }
    
    return false;
}