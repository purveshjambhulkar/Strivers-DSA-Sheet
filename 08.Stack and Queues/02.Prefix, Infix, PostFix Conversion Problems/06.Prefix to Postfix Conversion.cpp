// problem link - https://www.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        stack<string> st;
        
        //instead for reversing we can also start iterating from the last to first of the string
        //but just for simplicity we are reversing it
        reverse(pre_exp.begin() , pre_exp.end());
        
        for(char ch : pre_exp){
            if(isalnum(ch)){
                st.push(string(1 , ch));
            }else {
                string s1 = st.top(); 
                st.pop();
                string s2 = st.top(); 
                st.pop();
                
                string temp = s1 + s2 + ch;
                
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
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends