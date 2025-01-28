    //{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        
        //approach 2 - using 2 pointers
        
        int i = 0, j = 0;
        int n1 = a.size(), n2 = b.size();
        vector<int> ans;

        while (i < n1 && j < n2) {
            if (a[i] < b[j]) {
                // Add element from array a
                if (ans.empty() || ans.back() != a[i]) {
                    ans.push_back(a[i]);
                }
                i++;
            } else if (a[i] > b[j]) {
                // Add element from array b
                if (ans.empty() || ans.back() != b[j]) {
                    ans.push_back(b[j]);
                }
                j++;
            } else {
                // Both elements are equal, add only once
                if (ans.empty() || ans.back() != a[i]) {
                    ans.push_back(a[i]);
                }
                i++;
                j++;
            }
        }

        // Process remaining elements in array a
        while (i < n1) {
            if (ans.empty() || ans.back() != a[i]) {
                ans.push_back(a[i]);
            }
            i++;
        }

        // Process remaining elements in array b
        while (j < n2) {
            if (ans.empty() || ans.back() != b[j]) {
                ans.push_back(b[j]);
            }
            j++;
        }

        return ans;
        
        
        //Approach - using sets
        // unordered_set <int> myset;
        // for(int i = 0 ; i < a.size() ; i++){
        //     myset.insert(a[i]);
        // }
        // for(int i = 0 ; i < b.size();i++){
        //     myset.insert(b[i]);
        // }
        
        // vector<int> ans;
        // for(int i : myset){
            
        //     ans.push_back(i);
        // }
        // sort(ans.begin() , ans.end());
        // return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends