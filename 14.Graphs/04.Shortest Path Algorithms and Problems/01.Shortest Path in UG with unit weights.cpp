// problem link - https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1



class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int V = adj.size();
        vector<int> visited(V , 0);
        
        vector<int> shortest(V , INT_MAX);
        
        // pair<node , dist>
        queue<pair<int, int>> q;
        shortest[src] = 0;
        q.push({src , 0});
        
        
        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
           
            
            for(auto n : adj[node]){
                if(shortest[n] > dist+1){
                    shortest[n] = dist + 1;
                    q.push({n , dist+1});
                }
            }
        }
        
        for (int i = 0; i < V; ++i) {
            if (shortest[i] == INT_MAX) {
                shortest[i] = -1;
            }
        }
        
        return shortest;
    }
};