// problem link - https://www.geeksforgeeks.org/problems/topological-sort/1


class Solution {
  public:
  
    void dfs( vector<vector<int>> &adj ,vector<int> &visited,stack<int> &st , int node ){
        
        visited[node] = 1;
        
        for(auto n : adj[node]){
            if(!visited[n]){
                dfs(adj , visited , st, n);
            }
        }
        
        st.push(node);
        
        
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
        }
        
        vector<int> visited(V , 0);
        stack<int> st;
        
        for(int i = 0 ; i < V ; i++){
            if(!visited[i]){
                dfs(adj , visited , st, i);
            }
        }
        
        
        vector<int> topo;
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
        
        return topo;
        
    }
};