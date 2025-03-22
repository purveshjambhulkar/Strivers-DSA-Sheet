//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int countSubstr(string& s, int k) {
        
        //Approach 2 
        int ans = 0;
        unordered_map<char, int> freq;
        int distinct = 0;
        int left = 0;

        // Expand the window with the right pointer
        for (int right = 0; right < s.length(); right++) {
            char curr = s[right];
            freq[curr]++;

            // If this is a new character, increment distinct count
            if (freq[curr] == 1) distinct++;

            // Shrink the window if distinct characters exceed k
            while (distinct > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) distinct--;
                left++;
            }

            // Count substrings when distinct characters are exactly k
            if (distinct == k) {
                ans += (right - left + 1);
            }
        }

        return ans;
        
        
        
        
        // code here.
        
        //Approach 1 - brute force + set (TLE)
        
        int ans = 0;
        
        // Sliding window approach
        for (int i = 0; i < s.length(); i++) {
            set<char> mySet;
            for (int j = i; j < s.length(); j++) {
                mySet.insert(s[j]);

                // If we have exactly 'k' distinct chars, count the substring
                if (mySet.size() == k) {
                    ans++;
                }
                
                // If we exceed 'k' distinct characters, stop this window
                if (mySet.size() > k) break;
            }
        }

        return ans;
        
        
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
        cout << ob.countSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends