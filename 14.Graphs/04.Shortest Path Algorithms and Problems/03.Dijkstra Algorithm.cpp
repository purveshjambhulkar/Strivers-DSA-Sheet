// problem-link - https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1


//APPROACH 2 - USING SET DS

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // pair<dist , node>
        set<pair<int ,int>> set;
        
        vector<int> dist(V , INT_MAX);
        set.insert({0 , src});
        
        dist[src] = 0;
        
        while(set.size() != 0){
            pair<int ,int> temp = *set.begin();
            
            int node = temp.second;
            int d = temp.first;
            set.erase(set.begin());
            
            for(auto n : adj[node]){
                int adjNode = n.first;
                int adjDist = n.second;
                
                if(d + adjDist < dist[adjNode]){
                    dist[adjNode] = d + adjDist;
                    set.insert({dist[adjNode] , adjNode});
                }
            }
        }
        
        return dist;
    }
};






//APPROACH 1 - USING PRIORITY QUEUE - MIN HEAP

// class Solution {
//   public:
//     vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
//         vector<vector<pair<int, int>>> adj(V);
//         for(auto edge : edges){
//             int u = edge[0];
//             int v = edge[1];
//             int w = edge[2];
//             adj[u].push_back({v, w});
//             adj[v].push_back({u, w});
//         }
        
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
//         vector<int> dist(V, INT_MAX);
//         dist[src] = 0;
//         pq.push({0, src});
        
//         while(!pq.empty()) {
//             int currDist = pq.top().first;
//             int node = pq.top().second;
//             pq.pop();
            
//             for(auto n : adj[node]) {
//                 int adjNode = n.first;
//                 int edgeWeight = n.second;
                
//                 if(currDist + edgeWeight < dist[adjNode]) {
//                     dist[adjNode] = currDist + edgeWeight;
//                     pq.push({dist[adjNode], adjNode});
//                 }
//             }
//         }
        
//         return dist;
//     }
// };
