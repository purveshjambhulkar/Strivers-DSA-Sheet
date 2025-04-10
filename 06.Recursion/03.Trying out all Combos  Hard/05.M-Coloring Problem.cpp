//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool pos(int node,vector<int>& color,vector<vector<int>>& adj,int col,int v){
      for(auto neighbor:adj[node]){
          if(color[neighbor]==col){
              return false;
          }
      }
      return true;
  }
  bool f(int node,vector<int>& color,int m,int v,vector<vector<int>>& adj){
      if(node==v){
          return true;
      }
      for(int i=1;i<=m;i++){
          if(pos(node,color,adj,i,v)){
              color[node]=i;
              if(f(node+1,color,m,v,adj)){
                  return true;
              }else {
              color[node]=0;
              }
          }
      }
      return false;
  }
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // code here
        vector<vector<int>> adj(v);
        for(auto it:edges){
            adj[it.first].push_back(it.second);
            adj[it.second].push_back(it.first);
        }
        vector<int> color(v,0);
       return (f(0,color,m,v,adj));
      
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends