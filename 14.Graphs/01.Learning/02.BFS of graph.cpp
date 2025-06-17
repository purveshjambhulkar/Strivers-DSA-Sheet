// problem link - https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1


class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int V = adj.size();
        vector<int> visited(V , 0);
        vector<int> bfs;
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            
            bfs.push_back(temp);
            
            for(auto it : adj[temp]){
                if(!visited[it]){
                visited[it] = 1;
                q.push(it);
                    
                }
            }
        }
        
        
        return bfs;
    }
};