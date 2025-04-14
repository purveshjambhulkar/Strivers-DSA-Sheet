// problem link - https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        
        stack<string> st;
        int n = pre_exp.length();
        
        for(int i = n-1; i >= 0;i--){
            if(isalnum(pre_exp[i])){
                st.push(string(1, pre_exp[i]));
            }else{
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                
                string temp = '(' + s1 + pre_exp[i] + s2 + ')';
                
                st.push(temp);
            }
        }
        
        return st.top();
        
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends