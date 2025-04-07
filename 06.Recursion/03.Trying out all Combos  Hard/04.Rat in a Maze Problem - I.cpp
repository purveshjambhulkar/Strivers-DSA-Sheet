//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    void findPathUtil(vector<vector<int>> &mat,vector<string> &ans, string temp,int n , int row, int col){
         // Check if out of bounds or on an obstacle
        if (row < 0 || row >= n || col < 0 || col >= n || mat[row][col] == 0) {
            return;
        }
        
        // If reached the bottom-right corner, store the path
        if (row == n - 1 && col == n - 1) {
            ans.push_back(temp);
            return;
        }
        
        // Mark cell as visited
        mat[row][col] = 0;
        
        // Move Left
        findPathUtil(mat, ans, temp + "L", n, row, col - 1);
        
        // Move Right
        findPathUtil(mat, ans, temp + "R", n, row, col + 1);
        
        // Move Up
        findPathUtil(mat, ans, temp + "U", n, row - 1, col);
        
        // Move Down (Fixed)
        findPathUtil(mat, ans, temp + "D", n, row + 1, col);
        
        // Backtrack (Unmark the cell)
        mat[row][col] = 1;
    }
  
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        vector<string> ans;
        string temp = "";
        int n = mat.size();
        
        findPathUtil(mat , ans, temp, n , 0 , 0);
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends