// problem link - https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1



//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        int n = s.length();
        int left= 0 ;
        int right = 0;
        int maxLen = -1;
        
        unordered_map<int , int> mpp;
        
        while(right < n){
            mpp[s[right]]++;
            
            while(mpp.size() > k){
                mpp[s[left]]--;
                if(mpp[s[left]] == 0){
                    mpp.erase(s[left]);
                }
                left++;
            }
            
            if(mpp.size() == k){
                maxLen = max(maxLen , right- left+ 1);
            }
            
            right++;
        }
        
        return maxLen;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends