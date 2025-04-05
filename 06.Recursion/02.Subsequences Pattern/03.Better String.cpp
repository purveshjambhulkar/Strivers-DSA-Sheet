//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    
    void subseqUtil(set<string>&set, string s , int index , string temp){
        //base case
        if(index == s.length()){
            set.insert(temp);
            return;
        }
        
        //include
        subseqUtil(set , s , index+1, temp + s[index]);
        
        //exclude
        subseqUtil(set, s , index+1 , temp );
        
    }
    
  
    string betterString(string s1, string s2) {
        // code here
        set<string> mySet1;
        set<string> mySet2;
        
        subseqUtil(mySet1, s1 , 0 , "");
        subseqUtil(mySet2, s2 , 0 , "");
        
        if(mySet1.size() >= mySet2.size()){
            return s1;
        }else{
            return s2;
        }
        
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution obj;
        string ans = obj.betterString(s1, s2);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends