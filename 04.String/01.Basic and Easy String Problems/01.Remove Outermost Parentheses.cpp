class Solution {
    public:
        string removeOuterParentheses(string s) {
    
            //Approach 2 - w/o using extra space
            string ans = "";
            int count = 0;
            for(int i = 0 ; i < s.length() ; i++){
                if(s[i] == '('){
                    if(count != 0){
                        ans.push_back(s[i]);
                    }
                    count++;
                }else{
                    count--;
                    if(count != 0){
                        ans.push_back(s[i]);
                    }
                }
            }
            return ans;
    
    
    
            // //Approach 1 - using stack
            // string ans = "";
            // stack<char> st;
            // for(int i = 0 ; i < s.length() ; i++){
            //     if(s[i] == '('){
            //         if(st.empty()){
            //             st.push(s[i]);
            //         }else{
            //             st.push(s[i]);
            //             ans.push_back(s[i]);
            //         }
            //     }else{
            //         st.pop();
            //         if(!st.empty()){
            //             ans.push_back(s[i]);
            //         }
            //     }
            
            // }
            // return ans;
        }
    };