// problem link - https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        
        stack<string> st;
        
        for(char ch : exp){
            if(isalnum(ch)){
                st.push(string(1, ch));
            }else{
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                string temp = '(' + s2 + ch + s1 + ')';
                
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
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    fclose(stdout);

    return 0;
}

// } Driver Code Ends