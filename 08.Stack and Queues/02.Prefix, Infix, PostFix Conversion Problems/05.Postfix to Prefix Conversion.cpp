// problem link - https://www.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        
        stack<string> st;
        
        for(char ch : post_exp){
            if(isalnum(ch)){
                st.push(string(1 , ch));
            }else {
                string s1 = st.top(); 
                st.pop();
                string s2 = st.top(); 
                st.pop();
                
                string temp = ch + s2 + s1;
                
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
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends