// problem link - https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1


// User function Template for C++


//questions related to bellman ford
// how does it handle -ev weight cycles?
// why n - 1 iterations only ?

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        for(int i = 0 ; i < V-1 ;i++){
            for(auto edge : edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                //relaxation
                if(dist[u] != 1e8 && dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        //nth iteration to check if there are any -ve weight cycles
        
        for(auto edge : edges){
             int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                //if relaxtion takes place it means -ve weight cylce exits, so return -1
                if(dist[u] != 1e8 && dist[u] + w < dist[v]){
                    return {-1};
                }
        }
        
        return dist;
        
        
    }
};
