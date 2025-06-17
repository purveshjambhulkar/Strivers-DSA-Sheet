// problem link - https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1


//Approach 2 - DFS traversal

//TLDR -

class Solution {
  public:
    
    bool dfsUtil(vector<vector<int>> &adj , vector<int> &visited , int node , int parent){
        
        visited[node] = 1;
        
        for(auto it : adj[node]){
            if(!visited[it]){
                if(dfsUtil(adj , visited , it ,node)){
                    return true;
                }
            }else if(it != parent){
                return true;
            }
        }
        
        return false;
    }
    

    bool isCycle(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected graph
        }
        
        vector<int> visited(V ,0);
        for(int i = 0 ; i < V ; i++){
            if(!visited[i]){
                if(dfsUtil(adj , visited , i, -1)){
                    return true;
                }
            }
        }
        
        return false;
        
    }
};



//Approach 1 - BFS traversal

//TLDR - in bfs traversal for every adjnode  if it is not visited then it must be the parent or else cycle exits

// class Solution {
//   public:
//     bool isCycleUtil(int start, vector<vector<int>>& adj, vector<int>& visited) {
//         queue<pair<int, int>> q;
//         visited[start] = 1;
//         q.push({start, -1}); // {current_node, parent}

//         while (!q.empty()) {
//             int node = q.front().first;
//             int parent = q.front().second;
//             q.pop();

//             for (int neighbor : adj[node]) {
//                 if (!visited[neighbor]) {
//                     visited[neighbor] = 1;
//                     q.push({neighbor, node});
//                 } else if (neighbor != parent) {
//                     return true; // Cycle found
//                 }
//             }
//         }

//         return false;
//     }

//     bool isCycle(int V, vector<vector<int>>& edges) {
//         // Step 1: Build adjacency list
//         vector<vector<int>> adj(V);
//         for (auto& edge : edges) {
//             int u = edge[0];
//             int v = edge[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u); // undirected graph
//         }

//         // Step 2: Check each component for a cycle
//         vector<int> visited(V, 0);
//         for (int i = 0; i < V; ++i) {
//             if (!visited[i]) {
//                 if (isCycleUtil(i, adj, visited)) {
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }
// };