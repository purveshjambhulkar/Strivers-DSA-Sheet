//problem - link - https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
  public:
  
    bool dfs(vector<vector<int>> &adj,vector<int> &visited ,  vector<int> &pathVisited ,int node ){
        
        visited[node] = 1;
        pathVisited[node] = 1;
        
        for(auto n : adj[node]){
            
            if(visited[n] == 0){
                if(dfs(adj , visited , pathVisited ,n)== true){
                    return true;
                }
            }else if(pathVisited[n] == 1){
                return true;
            }
            
        }
        
        pathVisited[node] = 0;
        return false;
        
        
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        vector<vector<int>> adj(V);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        
        vector<int> visited(V , 0);
        vector<int> pathVisited(V , 0);
        
        for(int i = 0 ;i< V ; i++ ){
            if(visited[i] == 0){
                if(dfs(adj , visited , pathVisited ,i) == true){
                    return true;
                }
            }
        }
        
        
        
        return false;
        
        
    }
};