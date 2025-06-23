// problem link - https://www.geeksforgeeks.org/problems/topological-sort/1


//APPROACH 2 - KAHNS ALGORITHM | bfs

//TLDr - find indrgree of all vertices
// add the vertices with indegree 0 into the queue
// remove one by one from queue and reduce the indgree of adj nodes 
// if the indegree of adj nodes become 0 then push them into queue


class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
        }
        
        vector<int> indegree(V , 0);
        
        queue<int> q;
        
        //calculate indegree
        for(int i = 0 ; i < V ; i++){
            for(auto n : adj[i]){
                indegree[n]++;
            }
        }
        
        //add in queue with indegree 0
        for(int i = 0 ; i < indegree.size() ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        
        vector<int> topo;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            topo.push_back(temp);
            
            for(auto n : adj[temp]){
                indegree[n]--;
                if(indegree[n] == 0){
                    q.push(n);
                }
            }
        }
        
        
        return topo;
        
        
    }
};

//APPROACH 1 - DFS TRAVERSAL


// class Solution {
//   public:
  
//     void dfs( vector<vector<int>> &adj ,vector<int> &visited,stack<int> &st , int node ){
        
//         visited[node] = 1;
        
//         for(auto n : adj[node]){
//             if(!visited[n]){
//                 dfs(adj , visited , st, n);
//             }
//         }
        
//         st.push(node);
        
        
//     }
  
//     vector<int> topoSort(int V, vector<vector<int>>& edges) {
//         // code here
//         vector<vector<int>> adj(V);
//         for(auto edge : edges){
//             int u = edge[0];
//             int v = edge[1];
            
//             adj[u].push_back(v);
//         }
        
//         vector<int> visited(V , 0);
//         stack<int> st;
        
//         for(int i = 0 ; i < V ; i++){
//             if(!visited[i]){
//                 dfs(adj , visited , st, i);
//             }
//         }
        
        
//         vector<int> topo;
//         while(!st.empty()){
//             topo.push_back(st.top());
//             st.pop();
//         }
        
//         return topo;
        
//     }
// };