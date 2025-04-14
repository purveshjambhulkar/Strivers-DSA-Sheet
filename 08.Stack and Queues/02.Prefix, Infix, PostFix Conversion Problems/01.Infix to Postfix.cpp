// problem link - https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card


//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   int precedence(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/' || op == '%') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }

    string infixToPostfix(string s) {
        stack<char> st;
        string result;

        for (char ch : s) {
            if (isalnum(ch)) {
                result += ch;
            } else if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); // pop the '('
            } else { // operator
                while (!st.empty() && st.top() != '(' &&
                       precedence(st.top()) >= precedence(ch)) {
                    result += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        // Pop remaining operators
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};



//{ Driver Code Starts.
//   Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends