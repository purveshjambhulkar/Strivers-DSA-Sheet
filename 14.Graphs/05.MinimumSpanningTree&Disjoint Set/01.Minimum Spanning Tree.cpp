// problem link - https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1



//Approach 1 - Prims Algorithm

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        
        // {dist , node}
        priority_queue<pair<int,int > , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        
        vector<int> visited(V , 0);
        pq.push({0 , 0});
        int sum = 0;
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            if(visited[node]){
                continue;
            }
            
            visited[node] = 1;
            sum+=dist;
            // if we told to return the MST then we can add it here in a ds
            
            
            
            for(auto n : adj[node]){
                int adjNode = n[0];
                int adjDist = n[1];
                
                if(!visited[adjNode]){
                    pq.push({adjDist , adjNode});
                }
            }
            
            
            
            
            
        }
        
        
        return sum;
        
        
    }
};