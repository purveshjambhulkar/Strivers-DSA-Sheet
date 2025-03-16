//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int num , int n){
        int ans = 1;
        for(int i = 0 ; i < n ; i++){
            ans *= num;
        }
        return ans;
    }
  
    int nthRoot(int n, int m) {
        // Code here.
        //Binary Search Approach
        int start = 1; 
        int end = m;
        while(start <= end){
            int mid = start + (end - start)/2;
            
            int temp = solve(mid , n);
            if(temp == m){
                return mid;
            }else if(temp > m){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return -1;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends