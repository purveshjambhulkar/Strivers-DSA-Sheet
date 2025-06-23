// problem link - https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1


//APPROACH 2 - TOPO SORT CONCEPT

//TLDR - DO A TOPO SORT AND IF THE FINAL ARRAY OF TOPO SORT CONTAINS LESS VERTICES THAN TOTAL VERTICES THEN CYCLE EXISTS

class Solution {
  public:
  
    
  
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        vector<vector<int>> adj(V);
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
        }
        
        
        //find inorder
        vector<int> indegree(V , 0);
        for(int i = 0 ; i < V ; i++){
            for(auto n : adj[i]){
                indegree[n]++;
            }
        }
        
        //add indegree 0 nodes in queue
        queue<int> q;
        
        for(int i = 0 ; i < V ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        
        //topo sort
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
        
        if(topo.size() == V){
            return false;
        }else{
            return true;
        }
        
        
    }
};

//APPROACH 1 - DFS - visited and pathVisited concept
// class Solution {
//   public:
  
//     bool dfs(vector<vector<int>> &adj,vector<int> &visited ,  vector<int> &pathVisited ,int node ){
        
//         visited[node] = 1;
//         pathVisited[node] = 1;
        
//         for(auto n : adj[node]){
            
//             if(visited[n] == 0){
//                 if(dfs(adj , visited , pathVisited ,n)== true){
//                     return true;
//                 }
//             }else if(pathVisited[n] == 1){
//                 return true;
//             }
            
//         }
        
//         pathVisited[node] = 0;
//         return false;
        
        
//     }
  
//     bool isCyclic(int V, vector<vector<int>> &edges) {
//         // code here
        
//         vector<vector<int>> adj(V);
//         for(auto edge: edges){
//             int u = edge[0];
//             int v = edge[1];
//             adj[u].push_back(v);
//         }
        
//         vector<int> visited(V , 0);
//         vector<int> pathVisited(V , 0);
        
//         for(int i = 0 ;i< V ; i++ ){
//             if(visited[i] == 0){
//                 if(dfs(adj , visited , pathVisited ,i) == true){
//                     return true;
//                 }
//             }
//         }
        
        
        
//         return false;
        
        
//     }
// };