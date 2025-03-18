//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        //Approach 1 - Brute force
        
        vector<int> temp;
        for(int i = 0 ; i < mat.size() ; i++){
            temp.insert(temp.end(), mat[i].begin() , mat[i].end());
        }
        sort(temp.begin() , temp.end());
        return temp[temp.size()/2];
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends