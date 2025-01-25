//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void bubbleSortUtil(vector<int>& arr , int n){
        //base case
        if(n == 1)
        {
            return;
        }
        
        int didSwap = 0;
        for(int i = 0; i <= n-2 ; i++){
            
            if(arr[i] > arr[i+1]){
                swap(arr[i] , arr[i+1]);
                didSwap++;
            }
        }
        if(didSwap == 0){
            return;
        }
        
        //recusive call
        bubbleSortUtil(arr, n-1);
    }
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(vector<int>& arr) {
        // Your code here
        //push the max to the end by adjacent swapping
        
        //after each iteration max element goes to the last
        
        
        int n = arr.size();
        // for(int i = n-1 ; i>=1 ; i--){
        //     for(int j = 0; j < i;j++){
        //         if(arr[j] > arr[j+1]){
        //             swap(arr[j] , arr[j+1]);
        //         }
        //     }
        // }
        
        //Recursive Approach
        
        bubbleSortUtil(arr,n);
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;

        ob.bubbleSort(arr);
        for (int e : arr) {
            cout << e << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends