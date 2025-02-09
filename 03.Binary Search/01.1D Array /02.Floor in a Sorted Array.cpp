//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    int findFloor(vector<int>& arr, int k) {
        
        //Appoach 2 - Optimal (Binary Search)
        int right = arr.size() - 1;
    int left = 0;
    int floor = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // To prevent integer overflow
        
        if (arr[mid] == k) {
            return mid;  // Directly return k if found
        } else if (arr[mid] > k) {
            right = mid - 1;  // Move left
        } else {
            floor = mid;  // Possible floor value
            left = mid + 1;    // Move right
        }
    }   
    
    return floor;
        
        
        
        

        // //Approach 1 - Brute Force(Linear Search)
    
        // int floor = -1;
        // for(int i = 0 ; i < arr.size(); i++){
        //     if(arr[i] <= floor ){
        //         floor = arr[i];
        //     }
        //     else{
        //         return floor;
        //     }
        // }
        // return floor;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        int ans = ob.findFloor(arr, k);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends