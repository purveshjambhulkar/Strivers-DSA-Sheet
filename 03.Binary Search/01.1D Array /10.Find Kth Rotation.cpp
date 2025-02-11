//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        
        //Approach 2 - Binary Search -> O(log n)
        
        int start = 0 ;
        int end = arr.size() - 1;
        while(start <= end){
            int mid = (start +  end)/2;
            
            if(arr[mid] > arr[mid+1]){
                return mid + 1;
            }
            if(arr[mid] < arr[mid-1]){
                return mid ;
            }
            
            if(arr[mid + 1] <= arr[end]){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
            
            
        }
        
        
        return 0;
        
        
        // //Approach 1 - Brute Force (Linear Search) ->O(n)
        
        // for(int i = 0 ; i < arr.size() - 2;i++){
        //     if(arr[i] > arr[i+1]){
        //         return i + 1;
        //     }
        // }
        // return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends