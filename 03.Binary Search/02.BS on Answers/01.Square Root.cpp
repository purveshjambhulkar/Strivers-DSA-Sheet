//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        //Approach
        int low = 1; int high = n;
        int possibleAns = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(mid*mid == n){
                return mid;
            }else if(mid*mid > n){
              high = mid - 1;
            }else{
                possibleAns = mid;
                low =mid + 1;
            }
            
            
        }
        return possibleAns;
        
        
        // Your code goes here
        //Approach 1 - brute force
        // for(int i = 1; i <= n ; i++){
        //     if(i*i == n){
        //         return i;
        //     }
        //     if(i*i > n){
        //         return i-1;
        //     }
        // }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends