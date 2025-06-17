// problem link - https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

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
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> result;
        vector<int> visited(adj.size() , 0);
        
        for(int i = 0 ; i < adj.size() ; i++){
            if(!visited[i]){
                dfsUtil(adj , visited ,i,result);
            }
        }
        
        return result;
        
        
        
    }
};