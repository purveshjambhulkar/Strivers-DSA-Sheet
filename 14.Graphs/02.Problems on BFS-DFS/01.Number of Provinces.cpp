//Approach 1 - DFS traversal

//TLDR - simply use dfs traversal and count the no of dfs calls we call in main function
//we can also do this using BFS
class Solution {
public:
    void dfsUtil(vector<vector<int>>& isConnected, vector<int>& visited,
                 int node) {

        visited[node] = 1;

        for (int i = 0; i < isConnected[0].size(); i++) {
            if(isConnected[node][i] && !visited[i]){
                dfsUtil(isConnected, visited , i);
            }
        }
        
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        vector<int> visited(isConnected.size(), 0);
        int ans = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                ans++;
                dfsUtil(isConnected, visited, i);
            }
        }

        return ans;}
    };