//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        
        //Approach 2 - Binary Search Optimization
        sort(arr.begin() , arr.end());
        
        int floor = -1;
        int ceil = -1;
        int right = arr.size() - 1;
        int left = 0;
        
        //find Flooor
        while(left <= right){
            int mid = (left + right)/2;
            
            if(arr[mid] == x){
                floor = arr[mid];
                ceil = arr[mid];
                if(ceil != -1){
                    return {floor , ceil};
                }
                break;
            }else if(arr[mid] > x){
                right = mid - 1;
            }else{
                floor = arr[mid];
                left = mid + 1;
            }
            
        }
        
        
        right = arr.size() - 1;
        left = 0;
        
        //find Ceill
        while(left <= right){
            int mid = (left + right)/2;
            
            if(arr[mid] == x){
                ceil = arr[mid];
                return{floor , ceil};
            }else if(arr[mid] < x){
                left = mid + 1;
            }else{
                ceil = arr[mid];
                right = mid - 1;
            }
        }
        
        
        return {floor , ceil};
        
        
        
        
        // //Approach 1 - Brute 
        // sort(arr.begin() , arr.end());
        // int floor = -1;
        // int ceil = -1;
        // for(int i : arr){
        //     if(i <= x){
        //         floor = i;
        //     }
        //     if(i >= x){
        //         ceil = i;
        //         return{floor, ceil};
        //     }
        // }
        // return{floor, ceil};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n~\n";
    }
    return 0;
}
// } Driver Code Ends