//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        
        //Approach 2 - Works✅  |  tc = o(n)  and sc = 0(n)
        
        vector<int> ans;
        int n = arr.size();
        //last ele is always leader
        ans.push_back(arr[n-1]);
        
        int curr_max = arr[n-1];
        
        for(int i = n-2; i >=0; i--){
            if(arr[i] >= curr_max){
                ans.push_back(arr[i]);
                curr_max = arr[i];
            }
        }
        
        reverse(ans.begin() , ans.end());
        
        return ans;
        
        //Approach 1 - Brute Force TLE - TC = O(N^2) AND SC = O(N)
        // vector<int> ans;
        // for(int i = 0 ; i < arr.size() ; i++){
        //     if(i == arr.size() - 1){
        //         ans.push_back(arr[i]);
        //         break;
        //     }
        //     bool flag = true;
        //     for(int j = i+1 ; j < arr.size() ; j++){
        //         if(arr[i] < arr[j]){
        //             flag = false;
        //             break;
        //         } 
        //     }
            
        //     if(flag){
        //         ans.push_back(arr[i]);
        //     }
        // }
        
        // return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--) {
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.leaders(a);

        // Print the result in the required format
        if (result.empty()) {
            cout << "[]"; // Print empty brackets if no leaders are found
        } else {
            for (int i = 0; i < result.size(); i++) {
                if (i != 0)
                    cout << " ";
                cout << result[i];
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends