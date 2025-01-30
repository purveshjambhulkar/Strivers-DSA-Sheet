//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        //Approach 2 - 
        unordered_map<int, int> prefixSum;
        prefixSum[0] = -1; // Initialize with prefix sum 0 at index -1
        int sum = 0;
        int maxLen = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            
            // Check if (sum - k) exists in the prefixSum map
            if (prefixSum.find(sum - k) != prefixSum.end()) {
                maxLen = max(maxLen, i - prefixSum[sum - k]);
            }
            
            // Store the earliest occurrence of the current prefix sum
            if (prefixSum.find(sum) == prefixSum.end()) {
                prefixSum[sum] = i;
            }
        }
        
        return maxLen;
        //Approach 1 - Brute force = TLE
        // int maX = 0;
        // // Traverse all subarrays
        // for (int i = 0; i < arr.size(); i++) {
        //     int sum = 0;
        //     // Check each subarray starting from index i
        //     for (int j = i; j < arr.size(); j++) {
        //         sum += arr[j];  // Update the sum of the subarray
        //         if (sum == k) {  // If the sum matches k
        //             maX = max(maX, j - i + 1);  // Update the maximum length
        //         }
        //     }
        // }
        // return maX;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends