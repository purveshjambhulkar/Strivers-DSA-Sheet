//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countFreq(vector<int>& nums, int target) {
        // code here
        
        //Approach 2 - Binary Search o(log n) tc
        int first = -1, last = -1;
        int left = 0, right = nums.size() - 1;
    
            // Find first occurrence
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target) {
                    first = mid;
                    right = mid - 1; // Keep searching in the left half
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            
            if(first == -1){
                return 0;
            }
    
            // Reset pointers to search for last occurrence
            left = 0, right = nums.size() - 1;
    
            // Find last occurrence
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target) {
                    last = mid;
                    left = mid + 1; // Keep searching in the right half
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
    
            return last - first + 1;
        
    
        
        
        
        
        
        //Approach 1 - Brute Force(Linear Search) o(n) tc
        
        // int count = 0;
        // for(int i : arr){
        //     if(i == target){
        //         count++;
        //     }
        // }
        // return count;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends