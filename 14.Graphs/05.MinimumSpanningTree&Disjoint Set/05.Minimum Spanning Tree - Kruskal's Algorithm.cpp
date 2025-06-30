// problem link - https://www.geeksforgeeks.org/problems/minimum-spanning-tree-kruskals-algorithm/1


// KRUSKALS ALGORITHM - FINDING MST USING DISJOINT SET

class Disjoint{
    
    private : 
        vector<int> parent , rank;
        
    
    public : 
        
        Disjoint(int n ){
            parent.resize(n +1 );
            rank.resize(n+1 , 0);
            
            //initially mark parent of i as i itself
            for(int i = 0; i < parent.size() ; i++){
                parent[i] = i;
            }
        }
        
        int findParent(int node){
            if(parent[node] == node){
                return node;
            }
            //path compression
            
            return parent[node] = findParent( parent[node]);
        }
        
        void unionByRank(int node1 , int node2){
            
            //find ultimate parents of both the nodes
            int node1Parent = findParent( node1);
            int node2Parent = findParent( node2);
            
            if(node1Parent == node2Parent){
                return;
            }
            
            int rankNode1 = rank[node1Parent];
            int rankNode2 = rank[node2Parent];
            
            if(rankNode1 < rankNode2){
                parent[node1Parent] = node2Parent;
            }else if(rankNode2 < rankNode1){
                parent[node2Parent] = node1Parent;
            }else{
                parent[node2Parent] = node1Parent;
                rank[node2Parent]++;
            }
            
            
            
            
        }
        
    
};

class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        
         // Sort by weight (i.e., edges[i][2])
    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];  // Ascending order by weight
    });
        
        Disjoint ds(V);
        int sum = 0;
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            if(ds.findParent(u) != ds.findParent(v)){
                sum+=w;
                ds.unionByRank(u , v);
            }
        }
        
        return sum;
        
        
        
    }
};