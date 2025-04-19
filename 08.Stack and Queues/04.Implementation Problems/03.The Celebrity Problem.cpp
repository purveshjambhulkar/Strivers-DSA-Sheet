// problem link - https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        
        //Approach 2 - kinda 2 pointers
        
        int top = 0 ; 
        int down = mat.size() - 1;
        
        while(top < down){
            if(mat[top][down] == 1){
                top++;
            }else if(mat[down][top] == 1){
                down--;
            }else{
                top++;
                down--;
            }
        }
        
        if(top>down){
            return -1;
        }
        
        for(int i = 0 ; i < mat.size() ; i++){
            if(i == top){
                continue;
            }
            
            if(mat[top][i] == 0 && mat[i][top] == 1){
                
            }else{
                return -1;
            }
        }
        
        return top;
        
        
            
        //Approach 1 - brute force
        
        // for(int i = 0; i < mat.size(); i++){
            
        //     if (accumulate(mat[i].begin(), mat[i].end(), 0) == 1){
        //         bool flag = true;
        //         for(int j = 0; j < mat.size() ; j++){
        //             if(mat[j][i] != 1 ){
        //                 flag = false;
        //                 break;
        //             }
        //         }
        //         if(flag){
        //             return i;
        //         }
        //     }
        // }
        
        // return -1;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends