//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void sumUtil(vector<int> &arr , int target , int &count , int index , int temp){
        
        //base case 
        if(index == arr.size()){
            if(temp == target){
                count++;
            }
            return ;
        }
        
        
        //include 
        sumUtil(arr, target , count ,index + 1, temp + arr[index] );
        
        //exclude
        sumUtil(arr, target , count , index+1, temp );
    }
  
    int perfectSum(vector<int>& arr, int target) {
        // code here
        
        //This code has runtime error TLE which can be solved using DP
        
        int count = 0 ; 
        sumUtil(arr, target , count , 0 , 0);
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends