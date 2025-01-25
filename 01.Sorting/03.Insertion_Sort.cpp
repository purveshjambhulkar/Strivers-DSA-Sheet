//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Please change the array in-place
    
    void insertionSortUtil(vector<int>& arr, int n , int i){
        //base case
        if(i == n){
            return;
        }
        
        while(i > 0 && arr[i-1] > arr[i]){
            swap(arr[i-1] , arr[i]);
            i--;
        }
        
        //recursive call
        insertionSortUtil(arr , n , i+1);
    }
     
    
    void insertionSort(vector<int>& arr) {
        // code here
        
        //take a element and place it at its correct pos
        
        // for(int i = 0 ; i < arr.size() ; i++){
        //     int j = i ;
        //     while(j > 0 && arr[j-1] > arr[j]){
        //         swap(arr[j-1] , arr[j]);
        //         j--;
        //     }
        // }
        
        //recurive approach
        int n = arr.size();
        insertionSortUtil(arr, n,1);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        obj.insertionSort(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends