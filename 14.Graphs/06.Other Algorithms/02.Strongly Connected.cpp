// problem link - https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1


//Position this line where user code will be pasted.
class Solution {
  public:
  
  
  
    void dfs2(vector<vector<int>> &revAdj , vector<int> &visited , int node){
        visited[node] = 1;
        
        for(int n : revAdj[node]){
            
            if(!visited[n]){
                dfs2(revAdj , visited , n);
            }
            
        }
    }
  
    void dfs1(vector<vector<int>> &adj , stack<int> &st ,vector<int> &visited , int node){
        
        visited[node] = 1;
        
        for(auto n : adj[node]){
            if(!visited[n]){
                dfs1(adj , st , visited , n);
            }
        }
        
        st.push(node);
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        
        
        //make a dfs call and put all of them into stack just like topo sort order
        // reverse the edges
        //not pop from the stack and count the number of dfs call required
        
        stack<int> st;
        int V = adj.size();
        vector<int> visited(V , 0);
        
        for(int i = 0 ; i < V ;i++){
            if(!visited[i]){
                dfs1(adj, st , visited , i );
            }
        }
        
        
        // make reverse adjList
        
        
        vector<vector<int>> revAdj(V);
        
        for(int i = 0 ; i < V ; i++){
            
            // marked unvisited for further use of this visited array
            visited[i] = 0;
            
            for(int n : adj[i]){
                revAdj[n].push_back(i);
            }
            
            
        }
        
        //now pop the elements from stack and based on the revAdj count the number of dfs calls
        
        int ans = 0;
        
        while(!st.empty()){
    int node = st.top();
    st.pop();
    
    if(!visited[node]){
        ans++;
        dfs2(revAdj, visited, node);
    }
}

        
        
        return ans;
    
    }
};