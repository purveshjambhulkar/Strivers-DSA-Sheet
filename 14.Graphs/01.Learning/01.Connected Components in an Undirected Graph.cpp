// problem link - https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1

//Approach 2 - DFS traversal
class Solution {
  public:
  
    void dfsUtil(vector<vector<int>>& adj , vector<int> &visited , int node , vector<int> &result){
        visited[node] = 1;
        result.push_back(node);
        
        for(auto it : adj[node]){
            if(!visited[it]){
                dfsUtil(adj, visited , it , result);
            }
        }
    }
  
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        std::vector<std::vector<int>> adj(V);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> visited(V ,0);
        
        vector<vector<int>> all_Components;
        
        for(int i = 0 ; i < V ; i++){
            if(!visited[i]){
                vector<int> result;
                dfsUtil(adj ,visited , i , result);
                all_Components.push_back(result);
            }
        }
        
        return all_Components;
        
        
    }
};




//Approach 1 - BFS traversal - TLE

// class Solution {
// public:
//     std::vector<int> bfs(std::vector<std::vector<int>>& adj, std::vector<int>& visited, int start_node) {
//         std::queue<int> q;
//         q.push(start_node);
//         visited[start_node] = 1;
//         std::vector<int> current_component_nodes;

//         while (!q.empty()) {
//             int u = q.front();
//             q.pop();

//             current_component_nodes.push_back(u);

//             for (int v : adj[u]) {
//                 if (!visited[v]) {
//                     visited[v] = 1;
//                     q.push(v);
//                 }
//             }
//         }
//         return current_component_nodes;
//     }

//     std::vector<std::vector<int>> getComponents(int V, std::vector<std::vector<int>>& edges) {
//         std::vector<std::vector<int>> adj(V);
//         for (const auto& edge : edges) {
//             int u = edge[0];
//             int v = edge[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         std::vector<int> visited(V, 0);
//         std::vector<std::vector<int>> all_components;

//         for (int i = 0; i < V; ++i) {
//             if (!visited[i]) {
//                 std::vector<int> component = bfs(adj, visited, i);
//                 std::sort(component.begin(), component.end());
//                 all_components.push_back(component);
//             }
//         }
//         return all_components;
//     }
// };
