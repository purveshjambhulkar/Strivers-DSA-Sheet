//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int precedence(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }
  
    void infixToPostfix(string &s ,string &ans){
        
        stack<char> st;
        int n = s.length();
        int i = 0;
        
        while(i < n){
            
            if(isalpha(s[i])){
                ans += s[i];
            }else if(s[i] == '('){
                st.push(s[i]);
            }else if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
            }else{
                while(!st.empty()&& st.top() != '(' && precedence(s[i]) < precedence(st.top())){
                    ans+=st.top();
                    st.pop();
                }
            }
            
            i++;
            
        }
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
    }
  
    string infixtoPrefix(string pre_exp) {
        // Write your code here
        //reverse the string 
        //reverse the brackets
        //find postfix
        //reverse postfix
        
        reverse(pre_exp.begin() , pre_exp.end());
        
        for(int i = 0 ; i < pre_exp.length();i++){
            if(pre_exp[i] == '('){
                pre_exp[i] = ')';
            }else if(pre_exp[i] == ')'){
                pre_exp[i] = '(';
            }
        }
        
        string ans = "";
        infixToPostfix(pre_exp , ans);
        
        reverse(ans.begin() , ans.end());
        
        return ans;
        
        
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