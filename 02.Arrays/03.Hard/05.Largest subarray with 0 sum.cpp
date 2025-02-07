//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        
        //Approach 2 - Using hashmap
        int n = arr.size();
        unordered_map<int,int> mpp; 
    int maxi = 0;
    int sum = 0; 
    for(int i = 0;i<n;i++) {
        sum += arr[i]; 
        if(sum == 0) {
            maxi = i + 1; 
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); 
            }
            else {
                mpp[sum] = i;
            }
        }   
    }

    return maxi; 
        
    } 
        
        
        
        
    //     // Brute Force Approach - O(N^2) - TLE
        
    //     int n = arr.size();
    //     int maxLen = 0;

    //     for (int i = 0; i < n; i++) {
    //         int tempSum = 0;  // Initialize tempSum as 0 for every new starting index

    //         for (int j = i; j < n; j++) {
    //             tempSum += arr[j];

    //             // If sum is 0, update maxLen
    //             if (tempSum == 0) {
    //                 maxLen = max(maxLen, j - i + 1);
    //             }
    //         }
    //     }
        
    //     return maxLen;
    // }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends