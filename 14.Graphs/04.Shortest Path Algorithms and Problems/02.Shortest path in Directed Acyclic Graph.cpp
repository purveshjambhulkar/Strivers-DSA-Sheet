// problem link - https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1


// User function Template for C++
class Solution {
  public:
  
    void dfs(vector<vector<pair<int , int>>> &adj , vector<int> &visited , stack<int> &st , int node){
        
        
        visited[node] = 1;
        
        for(auto n : adj[node]){
            if(!visited[n.first]){
                dfs(adj , visited ,st,n.first);
            }
        }
        
        st.push(node);
    }
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        
        // pair<node , dist>
        vector<vector<pair<int , int>>> adj(V);
        for(auto n : edges){
            int u = n[0];
            int v = n[1];
            int dist = n[2];
            
            adj[u].push_back({v , dist});
        }
        
        
        vector<int> visited(V , 0);
        stack<int> st;
        for(int i = 0 ; i < V ; i++){
            if(!visited[i]){
                dfs(adj , visited , st , i);
            }
        }
        
        vector<int> shortest(V , INT_MAX);
        shortest[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto n : adj[node]){
                if (shortest[node] != INT_MAX && shortest[node] + n.second < shortest[n.first]){

                    shortest[n.first] = n.second + shortest[node];
                }
            }
        }
        
        for(int i = 0 ; i < V ; i++){
            if(shortest[i] == INT_MAX){
                shortest[i] = -1;
            }
        }
        
        return shortest;
        
    }
};
